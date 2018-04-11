#include <iostream>
#include <string>
#include "synth.h"
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

Synth::Synth (string inputFileName, string outputFileName)
{
    infile.open(inputFileName);
    
    outstream.open(outputFileName, ios::binary);
    
}
Synth::~Synth()
{
    
}

bool Synth::generateWave()
{
    // Parse the file
    string line;
    int line_count = 0;
    if (infile.is_open())
    {
        // write incorrect headers first:: program returns later and fixes the headers
        outstream.write(reinterpret_cast<const char*>(&ChunkID), sizeof ChunkID);
        outstream.write(reinterpret_cast<const char*>(&placeholder), sizeof placeholder);
        outstream.write(reinterpret_cast<const char*>(&Format), sizeof Format);
        writeSubChunk1();
        writeSubChunk2();
        while( getline(infile, line))
        {
            istringstream iss(line);
            char note = 'x', comma = 'x';
            //double amplitude = -1.0,
            double duration =-1.0;
            iss >>note >> comma >> amplitude >> comma>> duration;
            if (duration < 0)
            {
                cout << "line number: "<< line_count <<" Invalid duration" <<  endl;
                cout << " line skipped" <<endl;
                return false;
                
            }
            else if (amplitude < 0)
            {
                cout << "line number: " <<line_count << " invalid amplitude" << endl;
                cout << " line skipped" <<endl;
                return false;
            }
            
            else
            //generateWave();
                sample(note, duration);
            if (frequency < 0)
            {
                cout <<"line number: " << line_count <<"Invalid frequency" <<endl;
                cout << "line skipped" <<endl;
                return false;
            }
            
            //sample(note, duration,outstream);
            line_count++;
            
        }
        
        outstream.seekp(0);
        writeChunkHeader();
        writeSubChunk1();
        writeSubChunk2();
        //writeChunkHeader(outstream);
        
        cout << "NumSample: "<<samples <<endl;
        cout << "ChunkSize: "<<ChunkSize <<endl;
        cout << "Subchunk2Size: "<<Subchunk2Size <<endl;
        success =true;
        outstream.close();
    }
    if (success)
        return true;
    return false;
    
    
}
void Synth::writeChunkHeader()
{
    
    outstream.seekp(0);
    outstream.write(reinterpret_cast<const char*>(&ChunkID), sizeof ChunkID);
    ChunkSize = 4 + (8 + Subchunk1Size) + (8 +Subchunk2Size);
    outstream.write(reinterpret_cast<const char*>(&ChunkSize), sizeof ChunkSize);
    outstream.write(reinterpret_cast<const char*>(&Format), sizeof Format);
}
void Synth::writeSubChunk1()
{
    
    outstream.write(reinterpret_cast<const char*>(&Subchunk1ID), sizeof Subchunk1ID);
    outstream.write(reinterpret_cast<const char*>(&Subchunk1Size), sizeof Subchunk1Size);
    outstream.write(reinterpret_cast<const char*>(&AudioFormat), sizeof AudioFormat);
    outstream.write(reinterpret_cast<const char*>(&NumChannels), sizeof NumChannels);
    outstream.write(reinterpret_cast<const char*>(&SampleRate), sizeof SampleRate);
    outstream.write(reinterpret_cast<const char*>(&ByteRate), sizeof ByteRate);
    outstream.write(reinterpret_cast<const char*>(&BlockAlign), sizeof BlockAlign);
    outstream.write(reinterpret_cast<const char*>(&BitsPerSample), sizeof BitsPerSample);
    
    
}
void Synth::writeSubChunk2()
{
    
    outstream.write(reinterpret_cast<const char*>(&Subchunk2ID), sizeof Subchunk2ID);
    outstream.write(reinterpret_cast<const char*>(&Subchunk2Size), sizeof Subchunk2Size);
    //int16_t Data[NumSamples];
    //cout << NumSamples <<endl;
    
    
    
    
}
double Synth::noteFrequency(char note)
{
    if (note == 'c' || note == 'C')
    {
        return 261.63;
    }
    else if (note == 'd' || note == 'D')
    {
        return 293.66;
    }
    else if ( note == 'e' || note == 'E')
    {
        return 329.63;
    }
    else if (note == 'f' || note == 'F')
    {
        return 349.63;
    }
    else if (note == 'g' || note =='G')
    {
        return 392.0;
    }
    else if (note == 'a' || note == 'A')
    {
        return 440.0;
    }
    else if ( note == 'b' || note == 'B')
    {
        return 493.88;
    }
    else
        return -1.0;
}
void Synth::sample(char note, double duration)
{
    
    NumSamples = (duration *44100);
    samples = samples + NumSamples;
    Subchunk2Size = samples *2;
    frequency = noteFrequency(note);
    for (int n = 0; n < NumSamples; n++)
    {
        double amplitude1 = (amplitude/ maxAmplitude )* maxAmplitude;
        double value     = sin( (2.0 *M_PI * n * frequency) / SampleRate );
        int16_t data = (amplitude1 * value);
        
        outstream.write(reinterpret_cast<const char*>(&data), sizeof data);
        //outstream.write(reinterpret_cast<const char*>(&data2), sizeof data2);
        
    }
    //amplitude = (amplitude1 / maxAmplitude) * 32767;
    //samples = amplitude * maxAmplitude * sin(2.0 *M_PI * frequency * duration);
}

