#include "midiplayer.hpp"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDir>
#include <QFileDialog>
#include <cmath>
#include <QDebug>
#include <QMessageBox>


// Implement class MIDIPlayer here

MIDIPlayer::MIDIPlayer(QWidget *parent)
{
    mq = new message_queue<int> ;
    db = new shared_double_buffer<double> (1024); // initial double buffer.
    synthe =  new synthesizer (mq, db);
    // start a thread
    t1= std::thread(&synthesizer::synth,synthe);
    //
    QGridLayout *grid = new QGridLayout(parent);
    grid->addWidget(createFirstBox(), 0,0);
    grid->addWidget(createSecondBox(), 1,0);
    setLayout(grid);
    setWindowTitle("Milestone3");
    resize(380,220);
    // QAudio Initialization
    
    
    
    //Connect Signals and slots
    connect (play, SIGNAL(clicked()), SLOT(playMusic()));
    connect (pause, SIGNAL(clicked()), SLOT(pauseMusic()));
    connect (stop, SIGNAL(clicked()), SLOT(stopMusic()));
    connect (mute, SIGNAL(clicked()), SLOT(muteMusic()));
    connect (inputpath, SIGNAL(returnPressed()), SLOT(playMusic()));
    connect (volume, SIGNAL(valueChanged(int)), SLOT(setAudioVolume()));
}
MIDIPlayer::~MIDIPlayer()
{
    
    
    if (t1.joinable())
        t1.detach();
    mq->push(5);
    delete audio;
    
    //    // send a quit message to the synthesizer
    //    // wait until thread is finished using join.
}
QGroupBox *MIDIPlayer::createFirstBox()
{
    QGroupBox *groupBox = new QGroupBox(tr("MIDI Input"), this);
    inputpath = new QLineEdit(this);
    browse = new QPushButton("Browse", this);
    connect (browse, SIGNAL(clicked()), SLOT(browse_midi()));
    QHBoxLayout *hbox = new QHBoxLayout(this);
    inputpath->setObjectName("inputpath");
    hbox->addWidget(inputpath);
    hbox->addWidget(browse);
    groupBox->setLayout(hbox);
    return groupBox;
}
QGroupBox *MIDIPlayer::createSecondBox()
{
    QGroupBox *groupBox = new QGroupBox(tr("Audio Controls"));
    QHBoxLayout *hbox = new QHBoxLayout();
    QHBoxLayout *hbox2 = new QHBoxLayout();
    play = new QPushButton("Play", this);
    play->setObjectName("play");
    
    pause = new QPushButton("Pause", this);
    pause->setObjectName("pause");
    pause->setEnabled(false);
    stop = new QPushButton("Stop", this);
    stop->setObjectName("stop");
    stop->setEnabled(false);
    
    QLabel *v = new QLabel("Volume: ", this);
    volume = new QSlider(Qt::Horizontal,this);
    volume ->setObjectName("volume");
    volume->setSliderPosition(50);
    mute = new QPushButton("Mute", this);
    mute ->setObjectName("mute");
    hbox->addWidget(play);
    hbox->addWidget(pause);
    hbox->addWidget(stop);
    hbox2->addWidget(v);
    hbox2->addWidget(volume);
    hbox2->addWidget(mute);
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addLayout(hbox);
    vbox->addLayout(hbox2);
    groupBox->setLayout(vbox);
    return groupBox;
}

// message 0 means play, 1 means pause, 2 means stop.
void MIDIPlayer::playMusic()
{
    //mq->push(0);
    MIDIReader midi;
    std::ifstream infile;
    std::string in = getInputMidi();
    infile.open(in);
    if (infile.is_open())
    {
        
        bool a = midi.parse(infile);
        if (a)
        {
            
            if (state != 1)
            {
                TrackListType tl = midi.getAllTracks();
                synthe->setTrackList(tl);
                mq->push(0);
                pause->setEnabled(true);
                stop->setEnabled(true);
                play->setEnabled(false);
                browse->setEnabled(false);
            }
            if (state ==1)
            {
                mq->push(0);
                
                play->setEnabled(false);
            }
            
            sendMessage();
        }
    }
    else
    {
        
        QMessageBox::information(this, "File Not Found", "File is not found");
    }
    infile.close();
    state = 0;
    
}
void MIDIPlayer::pauseMusic()
{
    mq->push(1);
    audio->suspend();
    play->setEnabled(true);
    state = 1;
    
}
void MIDIPlayer::stopMusic()
{
    audio->reset();
    audio->stop();
    mq->push(2);
    play->setEnabled(true);
    pause->setEnabled(false);
    stop->setEnabled(false);
    browse->setEnabled(true);
    state = 2;
    
    // reset everything
}
void MIDIPlayer::muteMusic()
{
    volume->setValue(0);
}
void MIDIPlayer::browse_midi()
{
    QString directory = QFileDialog::getOpenFileName(this, tr("open file"), QDir::currentPath(),"MIDI FILE (*.mid)");
    inputpath->setText(directory);
    playMusic();
}

std::string MIDIPlayer::getInputMidi()
{
    std::string in = inputpath->text().toStdString();
    return in;
}
// Function to set the volume.
void MIDIPlayer::setAudioVolume()
{
    
    qreal v = volume->value()/100.0;
    if (audio != NULL)
        audio->setVolume(v);
}
void MIDIPlayer::sendMessage()
{
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    //get the lowest samplerates.
    auto rates = info.supportedSampleRates();
    int sampleRate = rates.at(0);
    for (int i = 1; i < rates.size(); ++i)
    {
        if (rates.at(i) < sampleRate)
            sampleRate = rates.at(i);
    }
    //sampleRate =44100;
    //Query the audio capabilities.
    QAudioFormat format;
    format.setSampleRate(sampleRate);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);
    if (!info.isFormatSupported(format))
    {
        qWarning()      << "Raw audio format not supported by backend, cannot play audio.";
    }
    else
    {
        audio = new QAudioOutput(format, this);
        
        mq->setSampleRate(sampleRate);
        db->setBufferSize(audio->bufferSize());
        if (db->getBufferSize() <= 0)
            db->setBufferSize(1024);
        audio->setNotifyInterval(25);
        setAudioVolume();
        device = audio->start();
        connect(audio, SIGNAL(notify()), this, SLOT(handleNotify()));
        connect(audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
        
        //device->startTransaction();
        handleNotify();
    }
}
void MIDIPlayer::handleStateChanged(QAudio::State newState)
{
    if(audio->error() == QAudio::UnderrunError)
    {
        qDebug() <<"Underrun1";
    }
    
    switch (newState) {
        case QAudio::IdleState:
            qDebug() <<"IDLE";
            
            break;
            
        case QAudio::StoppedState:
            // Stopped for other reasons
            
            if (audio->error() == QAudio::NoError)
            {
                // Clear double buffer and buffer for audio.
                db->stopPressed();
                buffer.clear();
                
            }
            if (audio->error() != QAudio::NoError) {
                // Error handling
                if(audio->error() == QAudio::UnderrunError)
                {
                    qDebug() <<"Underrun1";
                }
                
            }
            break;
        case QAudio::ActiveState:
            state = 0;
            break;
        case QAudio::SuspendedState:
            break;
        default:
            if(audio->error() == QAudio::UnderrunError)
            {
                qDebug() <<"Underrun3";
            }
            
            break;
    }
}
void MIDIPlayer::handleNotify()
{
    int byteFree = audio->bytesFree();
    int bytesToWrite = 0;
    if (byteFree > db->getBufferSize())
        bytesToWrite = db->getBufferSize();
    else if (byteFree <= db->getBufferSize())
        bytesToWrite = byteFree;
    int sampleToWrite = bytesToWrite >>1;
    bytesToWrite = 2*sampleToWrite;
    
    double s;
    //qDebug() << sampleToWrite;
    for (int i = 0; i < sampleToWrite; i++)
    {
        db->s_d_b_try_pop(s);
        //qDebug() << s;
        if (s == -99999)
        {
            play->setEnabled(true);
            pause->setEnabled(false);
            stop->setEnabled(false);
            browse->setEnabled(true);
        }
        else
        {
            int16_t temp = static_cast<int16_t>(lround(s));
            char *byte1 = reinterpret_cast<char *>(&temp);
            char *byte2 = ++byte1;
            buffer.push_back(*byte1);
            buffer.push_back(*byte2);
        }
        
    }
    if (bytesToWrite > 0) {
        device->write(buffer.data(), bytesToWrite);
    }
    
    buffer.clear();
}

