#include "interactive_instrument.hpp"

#include <iostream>

// TODO
InteractiveInstrument::InteractiveInstrument(const Track &track_)

{
    track = track_;
    current_iter = 0;
    harmonic1= false;
    harmonic2 = false;
    current = track.begin();
    is_halted = false;
}

void InteractiveInstrument::enableFirstHarmonic(bool value)
{
    harmonic1 = value;
}

void InteractiveInstrument::enableSecondHarmonic(bool value)
{
    harmonic2 = value;
}

void InteractiveInstrument::setVelocity(double value)
{
    velocity = value;
}

void InteractiveInstrument::setAttackTime(double value)
{
    attack_Time = value;
}

void InteractiveInstrument::setDecayTime(double value)
{
    decay_Time = value;
}

void InteractiveInstrument::setReleaseTime(double value)
{
    release_Time = value;
}

void InteractiveInstrument::reset()
{
    velocity = 1000.0; attack_Time = 0.062500; decay_Time = 0.050000; release_Time = 0.050000;
}

bool InteractiveInstrument::halted()
{
    return is_halted;
}

double InteractiveInstrument::sample(double deltaT)         //sample
{
    for (; current != track.end(); current++)
    {
        auto realTime = toRealTime(current->getTickTime());      //current in real-time
        if (realTime > deltaT + getCurrTime(deltaT))
        {
            break;
        }
        
        if (current->isNoteEvent() == true)
        {
            trackNote(*current);      //update NoteEvent and save note_active
        }
        else if (current->isTempoEvent() == true)
        {
            current_tempo = current->asTempoEvent();      //update TempoEvent
        }
        else if (current->isEndTrackEvent() == true)
        {
            is_halted = true;
            break;
        }
    }
    
    if (current == track.end())
    {
        is_halted = true;
    }
    
    auto result = sumAllNotes(deltaT);
    
    current_iter++;
    
    return result;
}

void InteractiveInstrument::trackNote(MIDIEvent event)
{
    NoteEvent note_event = event.asNoteEvent();
    int8_t note_number = note_event.getNoteNumber();
    //double elapsed_time = getCurrTime(deltaT) - toRealTime(event.getTickTime());
    
    if (note_event.getNoteOn() == true)
    {
        note_active.insert(std::make_pair(note_number, event));   //save noteon event
    }
}

double InteractiveInstrument::sumAllNotes(double deltaT)
{
    double result = 0.0;
    
    for (auto const &it : note_active)
    {
        result += sumSingleNote(it.second, deltaT);
    }
    return result;
}

double InteractiveInstrument::sumSingleNote(MIDIEvent event, double deltaT)
{
    
    NoteEvent note_event = event.asNoteEvent();
    int8_t note_num = note_event.getNoteNumber();
    double note_on = toRealTime(event.getTickTime());
    double note_off = toRealTime(getNoteOffTick(note_event.getNoteNumber(), event.getTickTime()));
    double note_elapsed = getCurrTime(deltaT) - note_on;
    
    double frequency = getFrequency(note_num);
    double harmonic = getHarmonic(frequency, note_elapsed);
    double envel = envelope( note_on, note_off, note_elapsed);
    double sum = velocity * envel * harmonic;
    
    return sum;
}

double InteractiveInstrument::getFrequency(int8_t noteNumber)
{
    if (noteNumber == 0) return 261.63 / 10.0; if (noteNumber == 1) return 277.18 / 10.0;  if (noteNumber == 2) return 293.66 / 10.0;  if (noteNumber == 3) return 311.13 / 10.0;  if (noteNumber == 4) return 329.63 / 10.0;  if (noteNumber == 5) return 349.63 / 10.0;  if (noteNumber == 6) return 369.994 / 10.0;  if (noteNumber == 7) return 392.0 / 10.0;  if (noteNumber == 8) return 415.305 / 10.0;  if (noteNumber == 9) return 440.0 / 10.0;  if (noteNumber == 10) return 466.164 / 10.0;  if (noteNumber == 11) return 493.88 / 10.0;
    if (noteNumber == 12) return 261.63 / 8.0;  if (noteNumber == 13) return 277.18 / 8.0;  if (noteNumber == 14) return 293.66 / 8.0;  if (noteNumber == 15) return 311.13 / 8.0;  if (noteNumber == 16) return 329.63 / 8.0;  if (noteNumber == 17) return 349.63 / 8.0;  if (noteNumber == 18) return 369.994 / 8.0;  if (noteNumber == 19) return 392.0 / 8.0;  if (noteNumber == 20) return 415.305 / 8.0;  if (noteNumber == 21) return 440.0 / 8.0;  if (noteNumber == 22) return 466.164 / 8.0;  if (noteNumber == 23) return 493.88 / 8.0;
    if (noteNumber == 24) return 261.63 / 6.0;  if (noteNumber == 25) return 277.18 / 6.0;  if (noteNumber == 26) return 293.66 / 6.0;  if (noteNumber == 27) return 311.13 / 6.0;  if (noteNumber == 28) return 329.63 / 6.0;  if (noteNumber == 29) return 349.63 / 6.0;  if (noteNumber == 30) return 369.994 / 6.0;  if (noteNumber == 31) return 392.0 / 6.0;  if (noteNumber == 32) return 415.305 / 6.0;  if (noteNumber == 33) return 440.0 / 6.0;  if (noteNumber == 34) return 466.164 / 6.0;  if (noteNumber == 35) return 493.88 / 6.0;
    if (noteNumber == 36) return 261.63 / 4.0;  if (noteNumber == 37) return 277.18 / 4.0;  if (noteNumber == 38) return 293.66 / 4.0;  if (noteNumber == 39) return 311.13 / 4.0;  if (noteNumber == 40) return 329.63 / 4.0;  if (noteNumber == 41) return 349.63 / 4.0;  if (noteNumber == 42) return 369.994 / 4.0;  if (noteNumber == 43) return 392.0 / 4.0;  if (noteNumber == 44) return 415.305 / 4.0;  if (noteNumber == 45) return 440.0 / 4.0;  if (noteNumber == 46) return 466.164 / 4.0;  if (noteNumber == 47) return 493.88 / 4.0;
    if (noteNumber == 48) return 261.63 / 2.0;  if (noteNumber == 49) return 277.18 / 2.0;  if (noteNumber == 50) return 293.66 / 2.0;  if (noteNumber == 51) return 311.13 / 2.0;  if (noteNumber == 52) return 329.63 / 2.0;  if (noteNumber == 53) return 349.63 / 2.0;  if (noteNumber == 54) return 369.994 / 2.0;  if (noteNumber == 55) return 392.0 / 2.0;  if (noteNumber == 56) return 415.305 / 2.0;  if (noteNumber == 57) return 440.0 / 2.0;  if (noteNumber == 58) return 466.164 / 2.0;  if (noteNumber == 59) return 493.88 / 2.0;
    if (noteNumber == 60) return 261.63;  if (noteNumber == 61) return 277.18;  if (noteNumber == 62) return 293.66; else if (noteNumber == 63) return 311.13;  if (noteNumber == 64) return 329.63;  if (noteNumber == 65) return 349.63;  if (noteNumber == 66) return 369.994;  if (noteNumber == 67) return 392.0;  if (noteNumber == 68) return 415.305;  if (noteNumber == 69) return 440.0;  if (noteNumber == 70) return 466.164;  if (noteNumber == 71) return 493.88; //
    if (noteNumber == 72) return 261.63 * 2.0;  if (noteNumber == 73) return 277.18 * 2.0;  if (noteNumber == 74) return 293.66 * 2.0;  if (noteNumber == 75) return 311.13 * 2.0;  if (noteNumber == 76) return 329.63 * 2.0;  if (noteNumber == 77) return 349.63 * 2.0;  if (noteNumber == 78) return 369.994 * 2.0;  if (noteNumber == 79) return 392.0 * 2.0;  if (noteNumber == 80) return 415.305 * 2.0;  if (noteNumber == 81) return 440.0 * 2.0;  if (noteNumber == 82) return 466.164 * 2.0;  if (noteNumber == 83) return 493.88 * 2.0;
    if (noteNumber == 84) return 261.63 * 4.0;  if (noteNumber == 85) return 277.18 * 4.0;  if (noteNumber == 86) return 293.66 * 4.0;  if (noteNumber == 87) return 311.13 * 4.0;  if (noteNumber == 88) return 329.63 * 4.0;  if (noteNumber == 89) return 349.63 * 4.0;  if (noteNumber == 90) return 369.994 * 4.0;  if (noteNumber == 91) return 392.0 * 4.0;  if (noteNumber == 92) return 415.305 * 4.0;  if (noteNumber == 93) return 440.0 * 4.0;  if (noteNumber == 94) return 466.164 * 4.0;  if (noteNumber == 95) return 493.88 * 4.0;
    if (noteNumber == 96) return 261.63 * 6.0;  if (noteNumber == 97) return 277.18 * 6.0;  if (noteNumber == 98) return 293.66 * 6.0;  if (noteNumber == 99) return 311.13 * 6.0;  if (noteNumber == 100) return 329.63 * 6.0;  if (noteNumber == 101) return 349.63 * 6.0;  if (noteNumber == 102) return 369.994 * 6.0;  if (noteNumber == 103) return 392.0 * 6.0;  if (noteNumber == 104) return 415.305 * 6.0;  if (noteNumber == 105) return 440.0 * 6.0;  if (noteNumber == 106) return 466.164 * 6.0;  if (noteNumber == 107) return 493.88 * 6.0;
    if (noteNumber == 108) return 261.63 * 8.0;  if (noteNumber == 109) return 277.18 * 8.0;  if (noteNumber == 110) return 293.66 * 8.0;  if (noteNumber == 111) return 311.13 * 8.0;  if (noteNumber == 112) return 329.63 * 8.0;  if (noteNumber == 113) return 349.63 * 8.0;  if (noteNumber == 114) return 369.994 * 8.0;  if (noteNumber == 115) return 392.0 * 8.0;  if (noteNumber == 116) return 415.305 * 8.0;  if (noteNumber == 117) return 440.0 * 8.0;  if (noteNumber == 118) return 466.164 * 8.0;  if (noteNumber == 119) return 493.88 * 8.0;
    if (noteNumber == 120) return 261.63 * 10.0;  if (noteNumber == 121) return 277.18 * 10.0;  if (noteNumber == 122) return 293.66 * 10.0;  if (noteNumber == 123) return 311.13 * 10.0;  if (noteNumber == 124) return 329.63 * 10.0;  if (noteNumber == 125) return 349.63 * 10.0;  if (noteNumber == 126) return 369.994 * 10.0;  if (noteNumber == 127) return 392.0 * 10.0;
    else return 0;
}

double InteractiveInstrument::envelope( double note_on, double note_off, double elapsedTime)
{
    
    double t0=note_on, t1= attack_Time, t2 =attack_Time+decay_Time, t3 = note_off - note_on,t4 =t3+release_Time, S = 0.8;
    //qDebug() << "T3" <<t3;
    if (elapsedTime >= t0 && elapsedTime <= t1)
    {
        //qDebug() << "A";
        return (1/t1)*elapsedTime;
    }
    else if (elapsedTime > t1 && elapsedTime <=t2)
    {
        //qDebug() <<"B";
        return 1-(elapsedTime-t1);
    }
    else if (elapsedTime > t2 && elapsedTime <=t3)
    {
        //qDebug()<<"C";
        //qDebug() <<"OFF"<<noteOffTime;
        //qDebug() <<"ON"<<noteOnTime;
        //qDebug () << "T3" << t3;
        return S;
    }
    
    else if (elapsedTime >t3 && elapsedTime <=t4)
    {
        //qDebug() <<"D";
        return (S -(S/(t4-t3))*(elapsedTime-t3));
    }
    else
    {
        
        return 0.0;
    }
}

double InteractiveInstrument::toRealTime(intmax_t tick)
{
    return (tick * current_tempo.getTempo()) / (pow(10.0, 6.0) * track.getTicksPerBeat());
}

double InteractiveInstrument::getCurrTime(double deltaT) const
{
    return current_iter * deltaT;
}

double InteractiveInstrument::getHarmonic(double frequency, double elapsed)
{
    if (harmonic1 && harmonic2)
        return 1.0 / 3.0 * (sin(2.0 * M_PI * frequency * elapsed) + sin(2.0 * M_PI * 2.0 * frequency * elapsed) + sin(2.0 * M_PI * 3.0 * frequency * elapsed));
    if (harmonic1)
        return 1.0 / 2.0 * (sin(2.0 * M_PI * frequency * elapsed) + sin(2.0 * M_PI * 2.0 * frequency * elapsed));
    if (harmonic2)
        return 1.0 / 2.0 * (sin(2.0 * M_PI * frequency * elapsed) + sin(2.0 * M_PI * 3.0 * frequency * elapsed));
    return sin(2.0 * M_PI * frequency * elapsed);
}

intmax_t InteractiveInstrument::getNoteOffTick(int8_t note_num, intmax_t note_on_tick)
{
    for (auto it = track.begin(); it != track.end(); it++)
    {
        if (it->getTickTime() < note_on_tick)
            continue;
        if (it->isNoteEvent())
        {
            auto note_event = it->asNoteEvent();
            if (note_event.getNoteNumber() != note_num)
                continue;
            if (note_event.getNoteOn())
                continue;
            
            return it->getTickTime();
        }
    }
    return prev(track.end())->getTickTime();
}


