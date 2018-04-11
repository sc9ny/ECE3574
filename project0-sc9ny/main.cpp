// Implement your program here
#include <iostream>
#include <fstream>
#include "synth.h"
using namespace std;



int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Incorrect Argument Count." <<endl;
    }
    else
    {
        Synth synth(argv[1], argv[2]);
        
        bool check =  synth.generateWave();
        if (check)
            return EXIT_SUCCESS;
        else
            return EXIT_FAILURE;
    }
}
