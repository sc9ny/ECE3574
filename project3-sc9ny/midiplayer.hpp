#ifndef MIDIPLAYER_HPP
#define MIDIPLAYER_HPP

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QGroupBox>
#include <string>
#include <iostream>
//#include "midi.hpp"
#include <thread>
#include <QAudioDeviceInfo>
#include <QAudioFormat>
#include <QAudioOutput>
#include "synthesizer.hpp"
//class synthesizer;
// define class MIDIPlayer here
  
class MIDIPlayer: public QWidget
{
    Q_OBJECT
public:
    //MIDIPlayer(QWidget *parent = 0, message_queue<int> *q = 0, shared_double_buffer<double> *d = 0);
    MIDIPlayer(QWidget * parent = 0);
    ~MIDIPlayer();
    void sendMessage();
    std::string getInputMidi();
private slots:
    void browse_midi();
    //void setSlider_value();
    //void browse_midi();
    void playMusic();
    void pauseMusic();
    void stopMusic();
    void muteMusic();
    void handleNotify();
    void setAudioVolume();
    void handleStateChanged(QAudio::State newState);
private:

    //GUI PART
    QLineEdit *inputpath;
    QPushButton *play;
    QPushButton *pause;
    QPushButton *stop;
    QSlider *volume;
    QPushButton * mute;
    QPushButton *browse;
    QGroupBox * createFirstBox();
    QGroupBox * createSecondBox();

    //DATA FIELD
    message_queue<int> * mq;
    QAudioOutput *audio = NULL;
    QIODevice *device = NULL;
    shared_double_buffer<double> *db;
    synthesizer *synthe;
    std::thread t1;
    int state = -1;
    std::vector <char> buffer;

};
#endif
