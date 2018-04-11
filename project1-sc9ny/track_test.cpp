/** \file Unit tests for Track Module
 */
//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "track.hpp"
#include <iostream>
#include <vector>

TEST_CASE( "Test Track module", "[track]" )
{
    Track track;
    TempoEvent tempo;
    NoteEvent note(false, 0,0);
    EndTrackEvent end;
    MIDIEvent tempo_(tempo, 5);
    MIDIEvent note_(note, 10);
    MIDIEvent end_(end, 15);
    //std::vector<MIDIEvent> MIDIList;
    REQUIRE(track.getTicksPerBeat() == 500000);
    //REQUIRE(MIDIList.size() == 0);
    
    SECTION("TESTING TRACK CONSTRUCTOR and getTicksPerBeat")
    {
        Track track(100000);
        REQUIRE(track.getTicksPerBeat() ==100000);
        Track track1(200000);
        REQUIRE(track1.getTicksPerBeat() ==200000);
    }
    
    SECTION("Testing ConstIteratorType Begin() and end()")
    {
        track.addTempoEvent(10, 5);
        track.addNoteEvent(9, 8, 10, 6);
        track.addEndEvent(10);
        //MIDIList.push_back(tempo_);
        //MIDIList.push_back(note_);
        //MIDIList.push_back(end_);
        //REQUIRE(MIDIList.size() == 3);
        REQUIRE(track.begin()->getTickTime() ==5);
        Track::ConstIteratorType it = track.end() -1;
        REQUIRE(it->getTickTime() == 10);
        REQUIRE (track.begin()->isTempoEvent() == true);
        REQUIRE ((track.begin()+1)->isNoteEvent() == true);
        REQUIRE ((track.begin()+2)->isEndTrackEvent() == true);
        REQUIRE ((track.begin()+3)== track.end());
        //REQUIRE(track.end() == MIDIList.end());
        
    }
    SECTION("TESTING addEndEvent()")
    {
        track.addEndEvent(20);
        track.addEndEvent(10);
        track.addEndEvent(40);
        track.addEndEvent(30);
        
        Track::ConstIteratorType it;
        REQUIRE(track.begin()->getTickTime() ==10);
        intmax_t previous =0;
        for (it = track.begin(); it != track.end(); it++)
        {
            intmax_t current = it->getTickTime();
            if (it != track.begin() && it != track.end())
            {
                REQUIRE(current > previous);
                REQUIRE(it->isEndTrackEvent() == true);
            }
            previous = current;
            
        }
    }
    SECTION("TESTING addTempoEvent()")
    {
        track.addTempoEvent(10, 5);
        track.addTempoEvent(10, 4);
        track.addTempoEvent(10, 6);
        track.addTempoEvent(10, 2);
        track.addTempoEvent(10, 7);
        Track::ConstIteratorType it;
        REQUIRE(track.begin()->getTickTime() ==2);
        intmax_t previous =0;
        for (it = track.begin(); it != track.end(); it++)
        {
            intmax_t current = it->getTickTime();
            if (it != track.begin() && it != track.end())
            {
                REQUIRE(current > previous);
                REQUIRE(it->isTempoEvent() == true);
            }
            previous = current;
            
        }
    }
    SECTION("Testing AddNoteEvent()")
    {
        track.addNoteEvent(9, 5, 20, 4);
        track.addNoteEvent(9, 10, 20, 1);
        track.addNoteEvent(9, 15, 20, 3);
        track.addNoteEvent(9, 20, 20, 2);
        track.addNoteEvent(9, 25, 20 ,2);
        Track::ConstIteratorType it;
        REQUIRE(track.begin()->getTickTime() ==1);
        intmax_t previous =0;
        for (it = track.begin(); it != track.end(); it++)
        {
            intmax_t current = it->getTickTime();
            double z =it->asNoteEvent().getNoteNumber();
            std::cout <<z << std::endl;
            if (it != track.begin() && it != track.end())
            {
                REQUIRE(current >= previous);
                REQUIRE(it->isNoteEvent() == true);
                REQUIRE (it->isNoteEvent() != false);
                REQUIRE (it->isTempoEvent() == false);
                REQUIRE (it->isEndTrackEvent() == false);
                REQUIRE (it->asNoteEvent().getNoteOn() == true);
                REQUIRE (it->asNoteEvent().getNoteOn() != false);
                
            }
            previous = current;
            
        }
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        it = track.begin()+1;
        REQUIRE(it->asNoteEvent().getNoteNumber() ==25);
        it = track.begin() +2;
        REQUIRE(it->asNoteEvent().getNoteNumber() == 20);
        
    }
    
}
    
    

