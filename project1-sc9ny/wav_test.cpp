/** \file Unit tests for WAV Module
 */
#include "catch.hpp"
#include "track.hpp"
#include "wav.hpp"
#include "signal.hpp"
#include "synthesizer.hpp"

TEST_CASE( "Test Functions in wav", "[wav]" ) {
    Track track;
    track.addNoteEvent(9, 60, 20, 100);// Real 1/10000
    track.addNoteEvent(8, 60, 20, 200);// Real 1/10000
    track.addNoteEvent(9, 61, 20, 300);// Real 1/10000
    track.addNoteEvent(8, 61, 20, 400);
    track.addNoteEvent(9, 62, 20, 500);// Real 1/10000
    track.addNoteEvent(8, 62, 20, 600);
    track.addNoteEvent(9, 63, 20, 700);// Real 1/10000
    track.addNoteEvent(8, 63, 20, 800);
    Signal signal = synthesize(track);
    REQUIRE (signal.size() >0);
    bool a = write_wav(signal, "SAMPLE.wav");
    REQUIRE (a == true);
    REQUIRE (track.getTicksPerBeat() == 500000);
    REQUIRE(signal.getSampleRate() == 44100);
    
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
    REQUIRE(signal[0] > -1.0);
   
    
}
