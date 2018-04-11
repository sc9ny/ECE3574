// TODO: implement the main entry point for synth here
#include "wav.hpp"
#include "midi.hpp"
#include "signal.hpp"
#include "track.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Incorrect Argument Count." <<endl;
        return EXIT_FAILURE;
    }
    else
    {
        MIDIReader midi;
        string fileName = argv[1];
        ifstream infile;
        infile.open(fileName);
        if (infile.is_open())
        {
            bool a = midi.parse(infile);
            if (a)
            {
                TrackListType tl = midi.getAllTracks();
                int i =0;
                for (TrackListType::iterator it = tl.begin(); it != tl.end(); it++)
                {
                    
                    //advance(it, i);
                    Track t = *it;
                    Signal signal = synthesize(*it);
                    string z = argv[2] + string("-") + to_string(i) + ".wav";
                    cout << z << endl;
                    bool write_wav_ = write_wav(signal, z);
                    if (write_wav_ == false)
                    {
                        cerr <<"FAILED Writing to wav file" <<std::endl;
                        return EXIT_FAILURE;
                    }
                        
                    
                    i++;
                }
            }
            
            
            
        }
        else
        {
            cout << "Input File Not Valid" <<endl;
            return EXIT_FAILURE;
        }
        
    }
        
    return EXIT_SUCCESS;
}

