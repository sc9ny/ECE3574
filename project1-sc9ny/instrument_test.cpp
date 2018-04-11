/** \file Unit tests for DefaultInstrument Module
*/
//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "track.hpp"
#include "instrument.hpp"
#include <iostream>
TEST_CASE( "Testing Functions in instrument.cpp", "[instrument]" ) {
    
    // construct track object with default ticks/beat
    Track track;
    
    
    
    SECTION("TEST CONSTRUCTOR")
    {
        track.addTempoEvent(1000000, 100); //Real = 1/5000;
        track.addNoteEvent(9, 8, 10, 150);// Real 3/10000
        track.addNoteEvent(8,8,10, 180);// Real 9/25000
        track.addEndEvent(200); //Real 1/2500
        Track::ConstIteratorType it ,it2,it3;
        it = track.begin();
        it2 = track.begin()+1;
        it3 = track.end() -1;
        DefaultInstrument inst(track);
        
        
        REQUIRE(it->getTickTime() == 100);
        REQUIRE(it2->getTickTime() ==150);
        REQUIRE(it3->getTickTime() ==200);
    }
    
    
    SECTION("Test Halted Function")
    {
        
        track.addTempoEvent(1000000, 100); //Real = 1/5000;
        
        track.addNoteEvent(9, 8, 10, 150);// Real 3/10000
        track.addNoteEvent(8,8,10, 180);// Real 9/25000
        track.addEndEvent(200); //Real 1/2500
        DefaultInstrument inst(track);
        Track::ConstIteratorType it;
        it = track.begin();
        REQUIRE(it->asTempoEvent().getTempo()== 1000000);
        inst.sample(0.00006);
        REQUIRE(inst.halted() == false);
        inst.sample(0.00006);
        REQUIRE(inst.halted() == false);
        inst.sample(0.00006);
        REQUIRE(inst.halted() == false);
        inst.sample(0.00006);
        REQUIRE(inst.halted() == false);
        inst.sample(0.00006);
        REQUIRE(inst.halted() == false);
        inst.sample(0.00006);
        REQUIRE(inst.halted() == false);
        inst.sample(0.00006);
        REQUIRE(inst.halted() == false);
        inst.sample(0.00006);
        REQUIRE(inst.halted() == true);
       
    }
    
    //SEGMENTATION FAULT. MAYBE CHECK (BY REQUIRE) IF  ALL THE FOLLOWING EVENTS ARE ADDED FIRST.
    SECTION("TEST SAMPLE FUNCTION")
    {
        Track track;
        
        Track::ConstIteratorType it;
        
        REQUIRE (track.getTicksPerBeat() ==500000);
        
        track.addTempoEvent(500000, 0); //Real = 0
        //REQUIRE(inst.halted() == false);
        track.addNoteEvent(9, 60, 20, 100);// Real 1/10000
        track.addNoteEvent(9, 64, 20, 100);// Real 1/10000
        track.addNoteEvent(9, 67, 20, 100);// Real 1/10000
        

        track.addNoteEvent(8, 60, 20, 200);// Real 1/5000
        track.addNoteEvent(8, 64, 20, 200);// Real 1/5000
        track.addNoteEvent(8, 67, 20, 200);// Real 1/5000

        track.addEndEvent(300); //Real 1/2500
        it = track.begin();
        REQUIRE(it->getTickTime() == 0);
        REQUIRE((it+1)->getTickTime() == 100);
        REQUIRE((it+2)->getTickTime() == 100);
        REQUIRE((it+3)->getTickTime() ==100);
        REQUIRE((it+7)->getTickTime() ==300);
        DefaultInstrument inst(track);
        REQUIRE (it->getTickTime() ==0);
        REQUIRE ((it+1) ->getTickTime() == 100);
        REQUIRE ((it+2) ->getTickTime() == 100);
        

        REQUIRE (inst.sample(0.0001) == 0.0);
        inst.sample(0.00005);
        REQUIRE(inst.halted() == false);
        inst.sample(0.00005);
        REQUIRE(inst.halted() == false);
        inst.sample(0.00005);
         REQUIRE(inst.halted() == false);
        inst.sample(0.00005);
         REQUIRE(inst.halted() == false);
        inst.sample(0.00005);
         REQUIRE(inst.halted() == false);
        inst.sample(0.00005);
         REQUIRE(inst.halted() == false);
        inst.sample(0.0001);
        inst.sample(0.0001);
        inst.sample(0.0001);
//        inst.sample(0.0001);
        REQUIRE(inst.halted() == true);
        
    }
    SECTION("TEST FOR MIDI_TEST1")
    {
    
        track.addTempoEvent(500000, 0); //Real = 0
        Track::ConstIteratorType it;
        it = track.begin();
        REQUIRE(it->asTempoEvent().getTempo() == 500000);
        
        track.addNoteEvent(9, 60, 20, 100);// Real 1/10000
        track.addNoteEvent(8, 60, 20, 200);// Real 1/10000
        track.addNoteEvent(9, 61, 20, 300);// Real 1/10000
        track.addNoteEvent(8, 61, 20, 400);
        track.addNoteEvent(9, 62, 20, 500);// Real 1/10000
        track.addNoteEvent(8, 62, 20, 600);
        track.addNoteEvent(9, 63, 20, 700);// Real 1/10000
        track.addNoteEvent(8, 63, 20, 800);
        //std:: cout << "A";
        track.addEndEvent(900);
        DefaultInstrument inst(track);
        for (int i =0; i < 38; i ++)
            inst.sample(0.000024);
        REQUIRE(inst.halted() == false);
        //inst.sample(0.00002267);
    }
//    SECTION ("TEST FREQUENCY")
//    {
//        track.addTempoEvent(500000,0);
//        track.addNoteEvent(9, 60, 20, 100);// Real 1/10000
//        Track::ConstIteratorType it;
//        it = track.begin();
//        it++;
//        DefaultInstrument inst(track);
//        double frequency = inst.getFrequency(it->asNoteEvent().getNoteNumber());
//        REQUIRE(frequency == 261.63);
//        track.addNoteEvent(9,400,20,200);
//        Track::ConstIteratorType it;
//        it = track.begin();
//        it++; it++;
//        double frequency1 = inst.getFrequency(it->asNoteEvent().getNoteNumber());
//        REQUIRE (frequency1 == 1);
//        
//    }
}
