/** \file The DefaultInstrument Module
 */
#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include "event.hpp"
#include "track.hpp"
#include <map>
#include <cmath>
#include <iostream>
/** The default instrument. A simple fixed length note instrument using a
 * a sinusoid weighted by an envelope function.
 */
class DefaultInstrument{
public:
    
    /** No default constructor. A DefaultInstrument must have an associated
     * track.
     */
    DefaultInstrument() = delete;
    
    /** Cannot be copied.
     */
    DefaultInstrument(const DefaultInstrument & ) = delete;
    
    /** Cannot be assigned.
     */
    DefaultInstrument & operator=(const DefaultInstrument & ) = delete;
    
    /** Construct a Default Instrument using the specified track.
     * \param track the track to read events from.
     */
    DefaultInstrument(const Track & track);
    
    /** Returns true of the DefaultInstrument has stopped processing events.
     * This can occu e.g. if all events have been consumed or a EndTrackEvent
     * has been processed.
     */
    bool halted();
    
    /** Return the sample after the (real) time increment. Samples the
     * instrument based on its state after processing all events prior
     * to this time.
     * \param deltaT the time increment in seconds.
     */
    double sample(double deltaT);
    //MIDI time is represented by a tick integer
    //T = microseconds per beat (defined by tempo)
    //M = MIDI clock ticks per beat (defined in MIDI file)
    //T' = (T/10^6) seconds per beat
    // hence seconds per MIDI clock tick = T'/M
    // Envelope function needs to be scaled depending on the time of the note (eg. if length of note = 2, multiply by 2) <- this is not part of implemetation for sample (this) function.
    // Process any new Track events that became active since the last sample time.
    // Sum the waveforms for the current active notes (the sigma equation)
    // must maintain a container of notes active at the current time (note on - add, note off - remove)
    //things need to maintain =  note number, note velocity, note duration (like milestone0), time turned on
    // Use a Track iterator to process all events up to the current sample time
    //Probably want to define private helper functions to:
    // convert a note number to a frequency, determine the length of a note, evaluate the envelope function, sum the active notes
    //delta t = 1/44100
    
    
private:
    //Track const *t;
    Track track_;
    double elapsed_time = 0;
    Track::ConstIteratorType it;
    std::vector<NoteEvent> aVec;
    std::map<int8_t, double> elapsed;
    std::vector<int8_t> inact;
    //double real_time = 0;
    double getFrequency(int8_t noteNumber);
    double freq = 0;
    intmax_t tempo = 0;
    int velocity = 0;
    double output = 0;
    double k =0;
    //State
    // container of active notes (map)
    //      for each active note: note number, time turned on, velocity
    //event iterator
    //  sample time
    // TODO
};
// repeatly call samle(double T) until halted is true

#endif
