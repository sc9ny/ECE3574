/** \file The InteractiveInstrument Module
 */
#ifndef INTERACTIVE_INSTRUMENT_HPP
#define INTERACTIVE_INSTRUMENT_HPP

#include "event.hpp"
#include "track.hpp"
#include "qinstrument.hpp"
#include <vector>
#include <map>
/** The interactive instrument.
 */
class InteractiveInstrument{
public:
    
    /** No default constructor. A InteractiveInstrument must have an associated
     * track.
     */
    InteractiveInstrument() = delete;
    
    /** Cannot be copied.
     */
    InteractiveInstrument(const InteractiveInstrument & ) = delete;
    
    /** Cannot be assigned.
     */
    InteractiveInstrument & operator=(const InteractiveInstrument & ) = delete;
    
    /** Construct a Interactive Instrument using the specified track.
     * \param track the track to read events from.
     */
    InteractiveInstrument(const Track & track);
    
    /** Returns true of the InteractiveInstrument has stopped processing events.
     * This can occu e.g. if all events have been consumed or a EndTrackEvent
     * has been processed.
     */
    bool halted();
    
    /** Enables the addition of a first harmonic to the instrument notes
     * \param value true if enabled, false if not
     */
    void enableFirstHarmonic(bool value);
    
    /** Enables the addition of a second harmonic to the instrument notes
     * \param value true if enabled, false if not
     */
    void enableSecondHarmonic(bool value);
    
    /** Sets the velocity of the notes.
     * \param value the new velocity
     */
    void setVelocity(double value);
    
    /** Sets the attack time of the envelope function.
     * \param value the new attack time
     */
    void setAttackTime(double value);
    
    /** Sets the decay time of the envelope function.
     * \param value the new decay time
     */
    void setDecayTime(double value);
    
    /** Sets the release time of the envelope function.
     * \param value the new release time
     */
    void setReleaseTime(double value);
    
    /** Resets the instrument to a default state.*/
    void reset();
    
    /** Return the sample after the (real) time increment. Samples the
     * instrument based on its state after processing all events prior
     * to this time.
     * \param deltaT the time increment in seconds.
     */
    double sample(double deltaT);
    
private:
    intmax_t getNoteOffTick(int8_t note_num, intmax_t note_on_tick);
    double getHarmonic(double frequency, double elapsed);
    double getCurrTime(double deltaT) const;
    double toRealTime(intmax_t tick);
    double envelope( double note_on, double note_off, double elapsedTime);
    double getFrequency(int8_t noteNumber);
    double sumSingleNote(MIDIEvent event, double deltaT);
    double sumAllNotes(double deltaT);
    void trackNote(MIDIEvent event);
    
    std::map<double, MIDIEvent> note_active;
    TempoEvent current_tempo;
    Track track;
    int current_iter =0;
    bool is_halted = false;
    Track::ConstIteratorType current;
    bool harmonic1 = false;
    bool harmonic2 = false;
    double velocity, attack_Time, decay_Time, release_Time;
    
    
    //    void initializeNoteInfo(int8_t noteNum, double realTime, double noteOff);
    //    double findNoteOffRealTime(Track::ConstIteratorType start, int8_t noteNum);
    //    double tickToRealTime(intmax_t tickTime);
    //    double sumActiveNotes();
    //    double envelope(double noteOnTime, double noteOffTime, double elapsedTime);
    //    double addSinusoids(double noteFrequency, double elapsedTime); //function n();
    //        //to- attack, t1- decay, t3 - sustain, t-4 release note duration
    //    static constexpr int NUM_NOTES = 128;
    
    //    struct NoteInfo{
    //        double timeOn;
    //        double timeOff;
    //        double frequency;
    //    }note_[NUM_NOTES];
    
    
    //    std::vector<NoteEvent> aVec;
    //    std::map <int8_t, double> elapsed;
    //    double elapsed_time = 0;
    //    Track track_;
    //    Track::ConstIteratorType it;
    //    double tempo = 0;
    //    int currentIter =0;
    //    double velocity, attackTime, decayTime, releaseTime = 0;
    //    bool harmonic1, harmonic2 = false;
    //double output = 0;
    
    // TODO
};

//Extensions to DefaultInstrument
//State now includes overall velocity (volume), attack/decay/release time, whether first/second harmonics
//are used (as set by QInstrument)

//Really want separate member functions for summation, E(), n()

// Summing active notes = time on to time off - time off inclues release time
//  - A note is active if the sample time is >= the note's time-on and <= the note's time off
//  - Time-off event denotes t_3, but the note tapers until t_4
//  - t_0 thru t_4 are elapsed times (not real time) since the note was turned on.
//      - t_3 is the difference between note-off time and the note-on time (t_3 = timeoff - time on)
//  - In MS1 all notes were 0.25sec

//For MS2 you probably want to add a function that picks ahead at the note-off event/time for the
//current note-on/time <- copy the orignal iterator in a function. Get Note off event using note number.
//  - Not necesarily the next event
//  - Probably should use a separate iterator
//  - Don't forget to add the release time to the note-off time.



#endif

