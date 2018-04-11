#include <string>
#include <cstdint>
#include <iostream>
#include <fstream>
//#include <vector>
using namespace std;
class Synth{
public:
    Synth(string inputFileName, string outputFileName);
    ~Synth();
    bool generateWave();
    ifstream infile;
    ofstream outstream;
    
private:
    void sample(char note, double duration);
    //returns frequency based on note.
    double noteFrequency(char note);
    
    void writeChunkHeader();
    void writeSubChunk1();
    void writeSubChunk2();
    //void writeEverything();
    
    
    
    int samples = 0;
    double maxAmplitude = 32767;
    double frequency;
    double amplitude;
    const int8_t   ChunkID[4] = {'R','I','F','F'};        // "RIFF"
    int32_t  ChunkSize;         // 4 + (8 + SubChunk1Size) + (8 + SubChunk2Size)
    const int8_t   Format[4] = {'W','A','V','E'};         // "WAVE"
    const int8_t   Subchunk1ID[4] = {'f','m','t', ' '};   // "fmt "
    const int32_t  Subchunk1Size =16;    // 16
    const int16_t  AudioFormat =1;      // 1
    const int16_t  NumChannels =1;      // Mono = 1
    const int32_t  SampleRate =44100;       // samples per second, 44100
    const int32_t  ByteRate = 88200;         // SampleRate * NumChannels * BitsPerSample/8
    const int16_t  BlockAlign =2;       // NumChannels * BitsPerSample/8
    const int16_t  BitsPerSample =16;    // 8 bits = 8, 16 bits = 16
    const int8_t   Subchunk2ID[4] ={'d','a','t','a'};   // "data"
    int32_t  Subchunk2Size;    // NumSamples * NumChannels * BitsPerSample/8
    const int8_t placeholder[4] = {'-','-','-','-',};
    int NumSamples = 0;
    bool success  = false;
    
    
    
    
};
