#include "instrument.hpp"

double getFrequency(int8_t index);
double envelope(double t =0.25);
// TODO
DefaultInstrument::DefaultInstrument(const Track &track)
{
    //t = &track;
    track_ = track;
    it = track_.begin();
}

bool DefaultInstrument::halted()
{
    
    if (it->isEndTrackEvent())
    {
        std::cout <<"END TRACK" <<std::endl;
        //it = t->begin();
        //delete t;
        return true;
    }
    if (it == track_.end()-1)
    {
        //it = t->begin();
        return true;
    }
    return false;
}
double DefaultInstrument::sample(double deltaT)
{
    
    if (halted() == false)
    {
        if (it -> isTempoEvent())
        {
            //std::cout << "TEMPO" << std::endl;
            tempo = it ->asTempoEvent().getTempo();
        }
        //initial state.
        elapsed_time = k*deltaT;
        double real = ((it+1)->getTickTime() * tempo) /(pow(10,6)* track_.getTicksPerBeat());
//        std:: cout <<"itera: " <<it->getTickTime() <<std::endl;
//        std::cout << "elapsed: "<<elapsed_time <<std::endl;
//        std::cout << "real: "<<real <<std::endl;
        if (elapsed_time >=real)
        {
            it++;
            if (it->isNoteEvent())
            {
                NoteEvent a = it->asNoteEvent();
                // if event is on, push to vector
                if (it->asNoteEvent().getNoteOn())
                {
                    //std::cout << "NOTE ON2 DETECTED" << std::endl;
                    aVec.push_back(a);
                    int8_t n = a.getNoteNumber();
                    elapsed.insert(std::make_pair(n, 0));
                    /////////////////////////////////////////////////
                    while ((it+1) != track_.end() && (it+1)->getTickTime() == it->getTickTime())
                    {
                        it++;
                        NoteEvent a = (it)->asNoteEvent();
                        //std::cout << "NOTE ON DETECTED" << std::endl;
                        aVec.push_back(a);
                        int8_t n = a.getNoteNumber();
                        elapsed.insert(std::make_pair(n, 0));
                        
                    }
                    
                    /////////////////////////////////////
                }
                // if NoteEvent and NoteOn == false, remove the NoteEvent from map and vector.
                else if (it->asNoteEvent().getNoteOn() == false)
                {
                    
                      int8_t i = it->asNoteEvent().getNoteNumber();
                    if (elapsed[i] > 0.25)
                        elapsed.erase(i);

                }
            }
        }
        
        output = 0;
        if (aVec.size() != 0)
        {
            for (unsigned long z = 0; z < aVec.size(); z++)
            {
                int note_Number = aVec[z].getNoteNumber();
                //std::cout << "elapsed[note_n]" << elapsed[note_Number] <<std::endl;
                double env = envelope(elapsed[note_Number]);
                freq = getFrequency(note_Number);
                velocity = aVec[z].getNoteVelocity();
//                std:: cout << "NOTE NUM: " << note_Number <<std::endl;
//                std:: cout << "ENV: " << env <<std::endl;
//                std:: cout << "FREQ: " << freq << std::endl;

                if (freq == -1.0 || velocity < 0 || tempo <0)
                    return -9999;
                output = output +(200*velocity*env * sin(2* M_PI * freq *elapsed[note_Number]));
                //std::cout<< output<<std::endl;
            }
        }
        if (elapsed.size() != 0 )
        {
            for ( auto &x : elapsed)
            {
                x.second = x.second +deltaT;
                
            }
        }
        
    }
    k++;
    //std::cout<< "output: " <<output <<std::endl;
    return output;
}

// Define a helper function for envelope function
//@param double t elapsed time (delta t).
// maybe scale by constant 0.25
double envelope(double t)
{
    // scale depending on the length of the note
    double t0 = 0, t1=0.25*0.25, t2=0.45*0.25, t3=0.8*0.25,t4=1*0.25;
    
    
    if (t >=t0 && t<= t1)
    {
        //std:: cout << "dawdw" << t <<std::endl;
        return (1/t1)*t;
    }
    else if ( t>t1 && t<=t2)
    {
        //std:: cout << "a" <<std::endl;
        
        return 1-(t-t1);
    }
    else if (t >t2 && t<=t3)
    {
        //std:: cout << "b" <<std::endl;
        
        return 0.8;
    }
    else if (t >t3 && t <=t4)
    {
        //std:: cout << "c" <<std::endl;
        
        return 0.8 -((0.8/(t4-t3)) *(t-t3));
    }
    else
    {
        //std:: cout << "zzz" <<std::endl;
        return 0;
    }
    
    //return 0;
}




//Define helper function for frequency
double DefaultInstrument::getFrequency(int8_t noteNumber)
{
    if (noteNumber == 0) return 261.63 / 10.0; else if (noteNumber == 1) return 277.18 / 10.0; else if (noteNumber == 2) return 293.66 / 10.0; else if (noteNumber == 3) return 311.13 / 10.0; else if (noteNumber == 4) return 329.63 / 10.0; else if (noteNumber == 5) return 349.63 / 10.0; else if (noteNumber == 6) return 369.994 / 10.0; else if (noteNumber == 7) return 392.0 / 10.0; else if (noteNumber == 8) return 415.305 / 10.0; else if (noteNumber == 9) return 440.0 / 10.0; else if (noteNumber == 10) return 466.164 / 10.0; else if (noteNumber == 11) return 493.88 / 10.0;
    else if (noteNumber == 12) return 261.63 / 8.0; else if (noteNumber == 13) return 277.18 / 8.0; else if (noteNumber == 14) return 293.66 / 8.0; else if (noteNumber == 15) return 311.13 / 8.0; else if (noteNumber == 16) return 329.63 / 8.0; else if (noteNumber == 17) return 349.63 / 8.0; else if (noteNumber == 18) return 369.994 / 8.0; else if (noteNumber == 19) return 392.0 / 8.0; else if (noteNumber == 20) return 415.305 / 8.0; else if (noteNumber == 21) return 440.0 / 8.0; else if (noteNumber == 22) return 466.164 / 8.0; else if (noteNumber == 23) return 493.88 / 8.0;
    else if (noteNumber == 24) return 261.63 / 6.0; else if (noteNumber == 25) return 277.18 / 6.0; else if (noteNumber == 26) return 293.66 / 6.0; else if (noteNumber == 27) return 311.13 / 6.0; else if (noteNumber == 28) return 329.63 / 6.0; else if (noteNumber == 29) return 349.63 / 6.0; else if (noteNumber == 30) return 369.994 / 6.0; else if (noteNumber == 31) return 392.0 / 6.0; else if (noteNumber == 32) return 415.305 / 6.0; else if (noteNumber == 33) return 440.0 / 6.0; else if (noteNumber == 34) return 466.164 / 6.0; else if (noteNumber == 35) return 493.88 / 6.0;
    else if (noteNumber == 36) return 261.63 / 4.0; else if (noteNumber == 37) return 277.18 / 4.0; else if (noteNumber == 38) return 293.66 / 4.0; else if (noteNumber == 39) return 311.13 / 4.0; else if (noteNumber == 40) return 329.63 / 4.0; else if (noteNumber == 41) return 349.63 / 4.0; else if (noteNumber == 42) return 369.994 / 4.0; else if (noteNumber == 43) return 392.0 / 4.0; else if (noteNumber == 44) return 415.305 / 4.0; else if (noteNumber == 45) return 440.0 / 4.0; else if (noteNumber == 46) return 466.164 / 4.0; else if (noteNumber == 47) return 493.88 / 4.0;
    else if (noteNumber == 48) return 261.63 / 2.0; else if (noteNumber == 49) return 277.18 / 2.0; else if (noteNumber == 50) return 293.66 / 2.0; else if (noteNumber == 51) return 311.13 / 2.0; else if (noteNumber == 52) return 329.63 / 2.0; else if (noteNumber == 53) return 349.63 / 2.0; else if (noteNumber == 54) return 369.994 / 2.0; else if (noteNumber == 55) return 392.0 / 2.0; else if (noteNumber == 56) return 415.305 / 2.0; else if (noteNumber == 57) return 440.0 / 2.0; else if (noteNumber == 58) return 466.164 / 2.0; else if (noteNumber == 59) return 493.88 / 2.0;
    else if (noteNumber == 60) return 261.63; else if (noteNumber == 61) return 277.18; else if (noteNumber == 62) return 293.66; else if (noteNumber == 63) return 311.13; else if (noteNumber == 64) return 329.63; else if (noteNumber == 65) return 349.63; else if (noteNumber == 66) return 369.994; else if (noteNumber == 67) return 392.0; else if (noteNumber == 68) return 415.305; else if (noteNumber == 69) return 440.0; else if (noteNumber == 70) return 466.164; else if (noteNumber == 71) return 493.88; //
    else if (noteNumber == 72) return 261.63 * 2.0; else if (noteNumber == 73) return 277.18 * 2.0; else if (noteNumber == 74) return 293.66 * 2.0; else if (noteNumber == 75) return 311.13 * 2.0; else if (noteNumber == 76) return 329.63 * 2.0; else if (noteNumber == 77) return 349.63 * 2.0; else if (noteNumber == 78) return 369.994 * 2.0; else if (noteNumber == 79) return 392.0 * 2.0; else if (noteNumber == 80) return 415.305 * 2.0; else if (noteNumber == 81) return 440.0 * 2.0; else if (noteNumber == 82) return 466.164 * 2.0; else if (noteNumber == 83) return 493.88 * 2.0;
    else if (noteNumber == 84) return 261.63 * 4.0; else if (noteNumber == 85) return 277.18 * 4.0; else if (noteNumber == 86) return 293.66 * 4.0; else if (noteNumber == 87) return 311.13 * 4.0; else if (noteNumber == 88) return 329.63 * 4.0; else if (noteNumber == 89) return 349.63 * 4.0; else if (noteNumber == 90) return 369.994 * 4.0; else if (noteNumber == 91) return 392.0 * 4.0; else if (noteNumber == 92) return 415.305 * 4.0; else if (noteNumber == 93) return 440.0 * 4.0; else if (noteNumber == 94) return 466.164 * 4.0; else if (noteNumber == 95) return 493.88 * 4.0;
    else if (noteNumber == 96) return 261.63 * 6.0; else if (noteNumber == 97) return 277.18 * 6.0; else if (noteNumber == 98) return 293.66 * 6.0; else if (noteNumber == 99) return 311.13 * 6.0; else if (noteNumber == 100) return 329.63 * 6.0; else if (noteNumber == 101) return 349.63 * 6.0; else if (noteNumber == 102) return 369.994 * 6.0; else if (noteNumber == 103) return 392.0 * 6.0; else if (noteNumber == 104) return 415.305 * 6.0; else if (noteNumber == 105) return 440.0 * 6.0; else if (noteNumber == 106) return 466.164 * 6.0; else if (noteNumber == 107) return 493.88 * 6.0;
    else if (noteNumber == 108) return 261.63 * 8.0; else if (noteNumber == 109) return 277.18 * 8.0; else if (noteNumber == 110) return 293.66 * 8.0; else if (noteNumber == 111) return 311.13 * 8.0; else if (noteNumber == 112) return 329.63 * 8.0; else if (noteNumber == 113) return 349.63 * 8.0; else if (noteNumber == 114) return 369.994 * 8.0; else if (noteNumber == 115) return 392.0 * 8.0; else if (noteNumber == 116) return 415.305 * 8.0; else if (noteNumber == 117) return 440.0 * 8.0; else if (noteNumber == 118) return 466.164 * 8.0; else if (noteNumber == 119) return 493.88 * 8.0;
    else if (noteNumber == 120) return 261.63 * 10.0; else if (noteNumber == 121) return 277.18 * 10.0; else if (noteNumber == 122) return 293.66 * 10.0; else if (noteNumber == 123) return 311.13 * 10.0; else if (noteNumber == 124) return 329.63 * 10.0; else if (noteNumber == 125) return 349.63 * 10.0; else if (noteNumber == 126) return 369.994 * 10.0; else if (noteNumber == 127) return 392.0 * 10.0;
    else return 0;
}
    

