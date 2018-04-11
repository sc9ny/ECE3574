#include <QApplication>

#include <thread>
#include "midiplayer.hpp"

void gg ( MIDIPlayer *mp)
{

    mp->show();
    //a->exec();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *b = new QWidget;
//    message_queue<int> q;
//    shared_double_buffer<double> d(1024);
    MIDIPlayer MIDIplayer(b);
    //MIDIP
    //synthesizer synthe (&q, &MIDIplayer, &d);
    //std::thread t2(&gg,  &MIDIplayer);
    //t2.start();
    //std::thread t1(&synthesizer::synth, &synthe); // THREAD FOR SYNTHESIZER (THREAD 2)
    MIDIplayer.show(); //MAIN THREAD FOR GUI (THREAD 1)
    //t1.detach();
    return a.exec();

}
