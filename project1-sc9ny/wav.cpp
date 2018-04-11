#include "wav.hpp"

// TODO
/** \fn Write a signal to a WAV file. Returns true on success, false on failure.
 * The signal should be quantized into a 16 bit integer using rounding to nearest.
 * \param sound the signal to write.
 * \param filename the filename to write to.
 */
using namespace std;
const int8_t   ChunkID[4] = {'R','I','F','F'};        // "RIFF"
int32_t  ChunkSize;         // 4 + (8 + SubChunk1Size) + (8 + SubChunk2Size)
const int8_t   Format[4] = {'W','A','V','E'};         // "WAVE"
const int8_t   Subchunk1ID[4] = {'f','m','t', ' '};   // "fmt "
const int32_t  Subchunk1Size =16;    // 16
const int16_t  AudioFormat =1;      // 1
const int16_t  NumChannels =1;      // Mono = 1
//const int32_t  SampleRate =44100;       // samples per second, 44100
int32_t  ByteRate;         // SampleRate * NumChannels * BitsPerSample/8
const int16_t  BlockAlign =2;       // NumChannels * BitsPerSample/8
const int16_t  BitsPerSample =16;    // 8 bits = 8, 16 bits = 16
const int8_t   Subchunk2ID[4] ={'d','a','t','a'};   // "data"
int32_t  Subchunk2Size;    // NumSamples * NumChannels * BitsPerSample/8
//const int8_t placeholder[4] = {'-','-','-','-',};
void writeChunkHeader(ofstream &outstream);
void writeSubChunk1(ofstream &outstream, int32_t SampleRate);
void writeSubChunk2(ofstream &outstream);
bool write_wav(Signal & sound, const std::string &filename)
{
    ofstream outstream;
    outstream.open(filename, ios::binary);
    //Track t;
    
    //sound = synthesize(t);
    int32_t SampleRate = sound.getSampleRate();
    Subchunk2Size = int32_t(sound.size()*2);
    
    ByteRate = SampleRate*2;
    writeChunkHeader(outstream);
    writeSubChunk1(outstream, SampleRate);
    writeSubChunk2(outstream);
    int16_t sound_s =0;
    for (int i = 0; i < int(sound.size()); i++)
    {
        sound_s = sound[i];
        //sound_s = +sound_s + sound[i];
        if (sound_s == -9999)
            return false;
        outstream.write(reinterpret_cast<const char*>(&sound_s), sizeof sound_s);
    }
    
    outstream.close();
    return true;
}

void writeChunkHeader(ofstream &outstream)
{
    outstream.seekp(0);
    //HEADER
    outstream.write(reinterpret_cast<const char*>(&ChunkID), sizeof ChunkID);
    
    ChunkSize = 4 + (8 + Subchunk1Size) + (8 +Subchunk2Size);
    outstream.write(reinterpret_cast<const char*>(&ChunkSize), sizeof ChunkSize); ///
    outstream.write(reinterpret_cast<const char*>(&Format), sizeof Format);
}
void writeSubChunk1(ofstream &outstream, int32_t SampleRate)
{
    // CHUNK 1
    outstream.write(reinterpret_cast<const char*>(&Subchunk1ID), sizeof Subchunk1ID);
    outstream.write(reinterpret_cast<const char*>(&Subchunk1Size), sizeof Subchunk1Size);
    outstream.write(reinterpret_cast<const char*>(&AudioFormat), sizeof AudioFormat);
    outstream.write(reinterpret_cast<const char*>(&NumChannels), sizeof NumChannels);
    outstream.write(reinterpret_cast<const char*>(&SampleRate), sizeof SampleRate);
    outstream.write(reinterpret_cast<const char*>(&ByteRate), sizeof ByteRate);
    outstream.write(reinterpret_cast<const char*>(&BlockAlign), sizeof BlockAlign);
    outstream.write(reinterpret_cast<const char*>(&BitsPerSample), sizeof BitsPerSample);
}
void writeSubChunk2(ofstream &outstream)
{
    //CHUNK 2
    outstream.write(reinterpret_cast<const char*>(&Subchunk2ID), sizeof Subchunk2ID);
    outstream.write(reinterpret_cast<const char*>(&Subchunk2Size), sizeof Subchunk2Size); ///
}



