/** \file Synthesizer Module
 */
#ifndef SYNTHESIZER_HPP
#define SYNTHESIZER_HPP

#include "track.hpp"
#include "signal.hpp"
#include "instrument.hpp"
#include "shared_double_buffer.hpp"
#include "message_queue.hpp"
//#include "shared_double_buffer.hpp"
#include <fstream>
#include "midi.hpp"

/** \fn Synthesize a Track into a Signal.
 * Returned signal is empty on failure.
 * \param track the track to synthesize.
 */
class synthesizer{
public:
    synthesizer(message_queue<int> * q,  shared_double_buffer<double> *db);
    void synth();
    Signal synthesize(Track & track);
    void setTrackList(TrackListType t);
private:
    void playWave(Signal sig);
    message_queue <int>*mq;
    //MIDIPlayer * mp;
    shared_double_buffer<double> * db;
    int state = -1;
    TrackListType tl;
    TrackListType::iterator it;
    int message = -1;
    Signal signal;
};




// Very short once signal and DefaultInstrument classes are defined
#endif
