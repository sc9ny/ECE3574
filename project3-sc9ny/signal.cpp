#include "signal.hpp"
#include <iostream>
using namespace std;
// TODO
Signal::Signal(unsigned int sampleRate)
{
    sampleRate_ = sampleRate;
}
unsigned int Signal::getSampleRate()
{
    return sampleRate_;
}
void Signal::normalize()
{
    if (samples.size() != 0)
    {
        double max= *max_element(std::begin(samples), std::end(samples));
        double min = *min_element( std::begin(samples), std::end(samples));
        
        max = fabs(max);
        min = fabs(min);
        //cout << "MAX: " << max <<endl;
        //cout << "MIN: " <<min <<endl;
        //min = fabs(min);
        if (max > std::numeric_limits<int16_t>::max() )
        {
            for (int i =0; i < int(samples.size()); i++)
            {
                
                samples[i] = int16_t((samples[i]/max) *32767);
                //cout << samples[i] <<endl;
            }
        }
    }
    

}
void Signal::push_back(double value)
{
    samples.push_back(value);
}
size_t Signal::size()
{
    return samples.size();
}
double Signal::operator[](size_t index)
{
    return samples[index];
}
