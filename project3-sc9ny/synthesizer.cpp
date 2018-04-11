#include "synthesizer.hpp"
//#include "shared_double_buffer.hpp"
#include <QDebug>
#include <QMessageBox>
// TODO

// method implementing the thread:
// - should return only when a Quit message is sent
// - alternate between::
//  - checking the messagequeue and processing any new messages
//  - if in the play state then generating the next sample and attempting to push it to the sharedDoubleBuffer.
Signal synthesizer:: synthesize(Track & track)
{
    //qDebug() <<"AA";
    Signal signal (mq->getSampleRate());
    DefaultInstrument inst (track);
    double delta = 1.0/mq->getSampleRate();
    qDebug() <<signal.getSampleRate();
    while(inst.halted() == false)
    {
        double sam = (inst.sample(delta));
        signal.push_back(sam);
    }
    signal.normalize();
    return signal;
}
synthesizer::synthesizer(message_queue<int> *q,  shared_double_buffer<double> * d)
{
    mq = q;
    //mp = m;
    db = d;
}
void synthesizer::setTrackList(TrackListType t)
{

    for (TrackListType::iterator it = t.begin(); it != t.end(); it++)
    {
        tl.push_back(*it);
    }
}
void synthesizer::playWave(Signal sig)
{
    int16_t sound_s = 0;
    for (int i = 0; i <int(sig.size()); i ++)
    {
        sound_s = sig[i];

        bool a = db->s_d_b_push(sound_s);
        if (a == false)
        {
            db->s_d_b_wait_and_push(sound_s);
        }

        mq->try_pop(message);
        //qDebug() << message;
        if (message == 0)
        {
            state = 0;
            //db->quitSuspension();
        }
        if (message == 1)
        {
            qDebug() << message;
            state = 1;
            mq->wait_and_pop(message);

        }
        if (message ==2)
        {

            mq->wait_and_pop(message);
            //db->stopPressed();
            mq->stopPressedMQ();
            state = 2;
            break;
        }

        if (message == 5)
        {
            return;
        }



    }

}

void synthesizer::synth()
{
    mq->wait_and_pop(message);

    while (message != 5)
    {

        //qDebug() << "MESSAGE:" <<message;
        if (message ==0)
        {
            message = -1;
            state = 0;
            Signal signal;
            for (it = tl.begin(); it != tl.end(); it++)
            {

                signal =synthesize(*it);
                playWave(signal);
                if (message == 2)
                {
                    tl.clear();
                    break;
                }
            }
            //end of track, send signal (-99999) to notifiy midiplayer to enable buttons.
            db->s_d_b_push(-99999);
            // Clear the tracklist.
            tl.clear();
        }
        message = -1;
        // NO stop button is pressed. Therefore send 0 samples.
        while (state != 2)
        {
            bool a = mq->empty();
            if (!a)
            {

                int message =-1;
                // if there is message, quit sending 0 samples.
                mq->try_pop(message);
                if (message == 5)
                {

                    return;
                }
                else
                    mq->push(message);

                break;
                ////////////
            }


            bool b = db->s_d_b_push(0);
            if (!b)
                db->s_d_b_wait_and_push(0);
        }
        mq->try_pop(message);
    }



}
