#include "synthesizer.hpp"

// TODO
Signal synthesize(Track & track)
{
    Signal signal (44100);
    DefaultInstrument inst (track);
    double delta = 1.0/signal.getSampleRate();
    while(inst.halted() == false)
    {
        double sam = (inst.sample(delta));
        signal.push_back(sam);
    }
    signal.normalize();
    return signal;
}
