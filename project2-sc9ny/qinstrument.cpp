#include "qinstrument.hpp"
#include <QGridLayout>
#include <QLabel>
#include <QFormLayout>
#include <QDir>
#include <QFileDialog>

#include <QMessageBox>
#include <fstream>
Signal synthesizer(Track track);
// TODO
QInstrument::QInstrument(QWidget *parent)
{
    QGridLayout *grid = new QGridLayout(parent);
    grid-> addWidget(createFirstBox(), 0,0);
    grid-> addWidget(createSecondBox(), 1,0);
    grid ->addWidget(createThirdBox(), 2,0);
    grid ->setObjectName("grid");
    synthesize = new QPushButton(parent);
    synthesize->setObjectName("synthesize");
    synthesize->setText("Synthesize");
    connect(midi_browse, SIGNAL(clicked()), SLOT(browse_midi()));
    connect(wav_browse, SIGNAL(clicked()), SLOT(browse_wav()));
    connect(velocitySpin, SIGNAL(valueChanged(double)), SLOT(setVelocity()));
    connect(attackSpin, SIGNAL(valueChanged(double)), SLOT(setAttack()));
    connect(decaySpin, SIGNAL(valueChanged(double)), SLOT(setDecay()));
    connect(releaseSpin, SIGNAL(valueChanged(double)), SLOT(setRelease()));
    connect(synthesize, SIGNAL(clicked()), SLOT(write_out()));
    connect(radio1, SIGNAL(clicked()), SLOT(radio1Status()));
    connect(radio2, SIGNAL(clicked()), SLOT(radio2Status()));
    grid->addWidget(synthesize);
    setLayout(grid);
    setWindowTitle("Milestone2");
    resize(480, 320);
    
}

QGroupBox *QInstrument::createFirstBox()
{
    
    QGroupBox *groupBox = new QGroupBox(tr("Instrument Parameters"),this);
    groupBox->setObjectName("groupBox1");
    radio1 = new QRadioButton(tr("Enable First Harmonic"),this);
    radio2 = new QRadioButton(tr("Enable Second Harmonic"),this);
    radio1 ->setAutoExclusive(false);
    radio2->setAutoExclusive(false);
    radio1->setObjectName("harmonic1");
    radio2->setObjectName("harmonic2");
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setObjectName("hbox1");
    hbox->addWidget(radio1);
    hbox->addWidget(radio2);
    
    QLabel * velocityLabel = new QLabel("Velocity:",this);
    QLabel * attackLabel = new QLabel("Attack Time (s):",this);
    QLabel * decayLabel = new QLabel("Decay Time (s):",this);
    QLabel * releaseLabel = new QLabel("Release Time (s):",this);
    
    
    velocitySpin = new QDoubleSpinBox(this);
    velocitySpin->setObjectName("velocity");
    velocitySpin->setDecimals(1);
    int32_t l = std::numeric_limits<int32_t>::max();
    velocitySpin->setRange(0,l);
    velocitySpin->setValue(1000);
    attackSpin = new QDoubleSpinBox(this);
    attackSpin->setObjectName("attack");
    attackSpin->setRange(0,1);
    attackSpin->setDecimals(6);
    attackSpin->setValue(0.0625000);
    //attackSpin->setRange(0, 0);
    decaySpin = new QDoubleSpinBox(this);
    decaySpin->setObjectName("decay");
    decaySpin->setRange(0,1);
    decaySpin->setDecimals(6);
    decaySpin->setValue(0.050000);
    releaseSpin = new QDoubleSpinBox(this);
    releaseSpin->setObjectName("release");
    releaseSpin->setRange(0,1);
    releaseSpin->setDecimals(6);
    releaseSpin->setValue(0.050000);
    
    attackSpin->setAlignment(Qt::AlignRight);
    velocitySpin->setAlignment(Qt::AlignRight);
    decaySpin->setAlignment(Qt::AlignRight);
    releaseSpin->setAlignment(Qt::AlignRight);
    
    
    QHBoxLayout *l1 = new QHBoxLayout();
    l1->setObjectName("l1");
    QHBoxLayout *l2 = new QHBoxLayout();
    l2->setObjectName("l2");
    QHBoxLayout *l3 = new QHBoxLayout();
    l3->setObjectName("l3");
    QHBoxLayout *l4 = new QHBoxLayout();
    l4->setObjectName("l4");
    
    l1->addWidget(velocityLabel);
    l1->addWidget(velocitySpin);
    
    l2->addWidget(attackLabel);
    l2->addWidget(attackSpin);
    
    l3->addWidget(decayLabel);
    l3->addWidget(decaySpin);
    
    l4->addWidget(releaseLabel);
    l4->addWidget(releaseSpin);
    
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setObjectName("mainLayout");
    mainLayout->addLayout(hbox);
    mainLayout->addLayout(l1);
    mainLayout->addLayout(l2);
    mainLayout->addLayout(l3);
    
    mainLayout->addLayout(l4);
    
    groupBox->setLayout(mainLayout);
    
    
    return groupBox;
}

QGroupBox *QInstrument::createSecondBox()
{
    QGroupBox *groupBox = new QGroupBox(tr("MIDI Input"),this);
    groupBox->setObjectName("groupBox2");
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox -> setObjectName("hbox2");
    midi_input = new QLineEdit(this);
    midi_input->setObjectName("midi_in");
    midi_browse = new QPushButton("Browse",this);
    midi_browse->setObjectName("midi_browse");
    hbox->addWidget(midi_input);
    hbox->addWidget(midi_browse);
    groupBox->setLayout(hbox);
    return groupBox;
    
}
QGroupBox *QInstrument::createThirdBox()
{
    QGroupBox *groupBox = new QGroupBox(tr("WAV Output"),this);
    groupBox->setObjectName("groupBox3");
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setObjectName("hbox3");
    wav_output = new QLineEdit(this);
    wav_output->setObjectName("wav_output");
    wav_browse = new QPushButton("Browse",this);
    wav_browse -> setObjectName("wav_browse");
    hbox->addWidget(wav_output);
    hbox->addWidget(wav_browse);
    groupBox->setLayout(hbox);
    return groupBox;
}
void QInstrument::browse_midi()
{
    //    QString directory =
    //                QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Find Files"), QDir::currentPath()));
    QString directory = QFileDialog::getOpenFileName(this, tr("open file"), QDir::currentPath(),"MIDI FILE (*.mid)");
    //midi_in = directory.toStdString();
    midi_input->setText(directory);
    
}
void QInstrument::browse_wav()
{
    //QString directory = QFileDialog::getOpenFileName(this, tr("open file"), QDir::currentPath(),"WAV FILE (*.wav)");
    QString directory =
    QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Find Files"), QDir::currentPath()));
    //wav_out = directory.toStdString();
    wav_output->setText(directory);
}
void QInstrument::setVelocity()
{
    velocity = velocitySpin->value();
    
}
void QInstrument::setAttack()
{
    attack = attackSpin->value();
    
    
}
void QInstrument::setDecay()
{
    decay = decaySpin->value();
    
}
void QInstrument::setRelease()
{
    release = releaseSpin->value();
    
}
double QInstrument::getVelocity()
{
    return velocity;
}
double QInstrument::getAttack()
{
    return attack;
}
double QInstrument::getDecay()
{
    return decay;
}
double QInstrument::getRelease()
{
    return release;
}
bool QInstrument::radio1Status()
{
    if (radio1->isChecked())
        radio1Checked = true;
    else
        radio1Checked = false;
    //qDebug() << radio1Checked;
    return radio1Checked;
}
bool QInstrument::radio2Status()
{
    if (radio2->isChecked())
        radio2Checked = true;
    else
        radio2Checked = false;
    //qDebug() << radio2Checked;
    return radio2Checked;
}
void QInstrument::write_out()
{
    MIDIReader midi;
    std::ifstream infile;
    midi_in = midi_input->text().toStdString();
    if (prev != midi_in && prev != "")
    {
        outNum++;
    }
    prev = midi_in;
    infile.open(midi_in);
    if (infile.is_open())
    {
        bool a = midi.parse(infile);
        if (a)
        {
            TrackListType tl = midi.getAllTracks();
            
            for (TrackListType::iterator it = tl.begin(); it != tl.end(); it++)
            {
                Track t = *it;
                InteractiveInstrument inst(t);
                //qDebug() << "signal.getSampleRate()";
                inst.setVelocity(getVelocity());
                //qDebug() << "signal.getSampleRate1()";
                inst.setAttackTime(getAttack());
                inst.setDecayTime(getDecay());
                inst.setReleaseTime(getRelease());
                inst.enableFirstHarmonic(statusRadio1());
                inst.enableSecondHarmonic(statusRadio2());
                Signal signal(44100.0);
                
                
                double delta = 1.0/signal.getSampleRate();
                
                while (inst.halted() == false)
                {
                    
                    double sam = inst.sample(delta);
                    
                    signal.push_back(sam);
                }
                
                
                signal.normalize();
                
                //return signal;
                
                //signal.normalize();
                
                if (statusRadio1() && statusRadio2())
                    wav_out = wav_output->text().toStdString() + "/output" +std::to_string(outNum) + "-0_harmonicboth.wav";
                if (statusRadio1() && statusRadio2() == false)
                    wav_out=wav_output->text().toStdString() + "/output" +std::to_string(outNum) + "-0_harmonic1.wav";
                if (statusRadio1() == false && statusRadio2() == true)
                    wav_out=wav_output->text().toStdString() + "/output" +std::to_string(outNum) + "-0_harmonic2.wav";
                if (statusRadio1() == false && statusRadio2() == false)
                    wav_out =wav_output->text().toStdString() + "/output" +std::to_string(outNum) + "-0"+".wav";
                if (velocity != 1000.0)
                    wav_out =wav_output->text().toStdString() + "/output" +std::to_string(outNum) + "_velocity-0"+".wav";
                if (attack != 0.062500 || decay != 0.050000 || release != 0.050000 )
                    wav_out =wav_output->text().toStdString() + "/output" +std::to_string(outNum) + "_longer-0"+".wav";
                if (velocity != 1000 && (attack != 0.062500 || decay != 0.050000 || release != 0.050000 ))
                    wav_out =wav_output->text().toStdString() + "/output" +std::to_string(outNum) + "_longer&velocity-0"+".wav";
                
                bool write_wav1 = write_wav(signal, wav_out);
                if (write_wav1 == false)
                {
                    
                    QMessageBox::information(this, tr("File not Written"), "File could not be written");
                }
                
            }
        }
    }
    else
        QMessageBox::information(this, tr("File Not Found"), "File is not found");
    
}
bool QInstrument::statusRadio1()
{
    return radio1Checked;
}
bool QInstrument::statusRadio2()
{
    return radio2Checked;
}
// helper function for synthesize button. This is same as synthesizer.hpp in Milestone1.

