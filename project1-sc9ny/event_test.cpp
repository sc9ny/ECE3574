/** \file Unit tests for Event Module
*/
//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "event.hpp"
using namespace std;
TEST_CASE( "Testing TempoEvent class", "[tempo]" )
{
    TempoEvent tempoEvent(0);
    REQUIRE(tempoEvent.getTempo() ==0);
    
    SECTION("Test getTempo Function")
    {
        TempoEvent tempoEvent(10000000);
        REQUIRE(tempoEvent.getTempo() == 10000000);
        
    }
}
TEST_CASE( "Testing NoteEvent class" , "[note]")
{
    NoteEvent noteEvent(false, 0 ,0);
    REQUIRE (noteEvent.getNoteOn() == false);
    REQUIRE (noteEvent.getNoteNumber() == 0);
    REQUIRE (noteEvent.getNoteVelocity() == 0);
    
    SECTION ("TEST getNoteOn() Function")
    {
        NoteEvent noteEvent(true, 0, 0);
        REQUIRE (noteEvent.getNoteOn() == true);
    }
    SECTION("TEST getNoteNumber() Function")
    {
        NoteEvent noteEvent(false, 16, 0);
        REQUIRE(noteEvent.getNoteNumber() == 16);
        REQUIRE(noteEvent.getNoteOn() == false);
    }
    SECTION("TEST getNoteVelocity Funtion")
    {
        NoteEvent noteEvent(false, 0, 100);
        REQUIRE(noteEvent.getNoteVelocity() ==100);
    }
    
}

TEST_CASE("Testing MIDIEvent class", "[MIDIEvent]")
{
    TempoEvent tempoEvent(0);
    NoteEvent noteEvent(false, 0, 0);
    EndTrackEvent endTrackEvent;
    REQUIRE(noteEvent.getNoteOn() == false);
    REQUIRE(noteEvent.getNoteVelocity() == 0);
    REQUIRE(noteEvent.getNoteNumber() == 0);
    REQUIRE(tempoEvent.getTempo() == 0);
    
    SECTION("Test MIDIEvent holding TempoEvent")
    {
        MIDIEvent MIDI(tempoEvent, 0);
        REQUIRE (MIDI.isTempoEvent() == true);
        REQUIRE (MIDI.isNoteEvent() == false);
        REQUIRE (MIDI.isEndTrackEvent() == false);
        REQUIRE (MIDI.getTickTime() ==0);
        
    }
    SECTION ("Test MIDIEvent holding NoteEvent")
    {
        MIDIEvent MIDI(noteEvent, 10);
        REQUIRE (MIDI.isEndTrackEvent() == false);
        REQUIRE(MIDI.isNoteEvent() == true);
        REQUIRE(MIDI.isTempoEvent() == false);
        REQUIRE(MIDI.getTickTime() ==10);
    }
    SECTION("Test MIDIEvent holding endTrackEvent")
    {
        MIDIEvent MIDI(endTrackEvent, 100);
        REQUIRE(MIDI.isEndTrackEvent() == true);
        REQUIRE(MIDI.isNoteEvent() == false);
        REQUIRE(MIDI.isTempoEvent() == false);
        REQUIRE(MIDI.getTickTime() == 100);
    }
    SECTION("Testing MIDIEvent asTempoEvent()")
    {
        MIDIEvent MIDI(tempoEvent, 0);
        REQUIRE(MIDI.isTempoEvent() == true);
        REQUIRE(MIDI.asTempoEvent().getTempo() == 0);
        
    }
    SECTION("Testing MIDIEvent asNoteEvent()")
    {
        MIDIEvent MIDI(noteEvent, 10);
        REQUIRE(MIDI.isNoteEvent() == true);
        REQUIRE(MIDI.asNoteEvent().getNoteOn() == false);
        REQUIRE(MIDI.asNoteEvent().getNoteNumber() == 0);
        REQUIRE(MIDI.asNoteEvent().getNoteVelocity() == 0);
        
    }
    
            
    
}


