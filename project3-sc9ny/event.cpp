#include "event.hpp"


using namespace std;


TempoEvent::TempoEvent(intmax_t t)
{
    tempo = t;
}
intmax_t TempoEvent::getTempo() const
{
    return tempo;
}


NoteEvent::NoteEvent(bool on, int8_t notenum, int8_t notevelocity)
{
    on_ = on;
    notenum_ = notenum;
    notevelocity_ = notevelocity;
    
}
bool NoteEvent::getNoteOn()
{
    return on_;
}
int8_t NoteEvent::getNoteNumber() const
{
    return notenum_;
}
int8_t NoteEvent::getNoteVelocity() const
{
    return notevelocity_;
}
MIDIEvent::MIDIEvent(TempoEvent e, intmax_t ticktime)
{
    
    tick_time = ticktime;
    event.tempoEvent_ = e;
    eventType = tempo;
    
}
/** Construct a MIDI event holding an EndTrackEvent at ticktime.
 */
MIDIEvent::MIDIEvent(EndTrackEvent e, intmax_t ticktime)
{
    event.endTrackEvent_ =e;
    tick_time = ticktime;
    eventType = end;
    
}

/** Construct a MIDI event holding a NoteEvent at ticktime.
 */
MIDIEvent::MIDIEvent(NoteEvent e, intmax_t ticktime)
{
    event.noteEvent_ =e;
    tick_time = ticktime;
    eventType = note;
}


/** True if event is a TempoEvent, else false.
 */
bool MIDIEvent:: isTempoEvent() const
{
    if (eventType == tempo)
        return true;
    
    return false;
}

/** True if event is an EndTrackEvent, else false.
 */
bool MIDIEvent::isEndTrackEvent() const
{
    if (eventType == end)
        return true;
    return false;
}

/** True if event is a NoteEvent, else false.
 */
bool MIDIEvent::isNoteEvent() const
{
    if (eventType == note)
        return true;
    return false;
}

/** Get the MIDI tick time of this event (ticks per beat)
 */
intmax_t MIDIEvent::getTickTime() const
{
    return tick_time;
}

/** Cast the MIDI event as a TempoEvent. Only valid if
 * isTempoEvent() returns true.
 */
TempoEvent MIDIEvent::asTempoEvent() const
{
    if (isTempoEvent())
    {
        return event.tempoEvent_;
        //how do you cast between two unrelated obj. No inheritance is being used.
    }
    return TempoEvent();
}

/** Cast the MIDI event as a NoteEvent. Only valid if
 * isNoteEvent() returns true.
 */
NoteEvent MIDIEvent::asNoteEvent() const
{
    if (isNoteEvent())
    {
        return event.noteEvent_;
    }
    return NoteEvent(true, 0,0);
}
