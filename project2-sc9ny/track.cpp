#include "track.hpp"
#include <iostream>

// TODO
Track::Track(intmax_t tick_per_beat)
{
    ticks_per_beat_ = tick_per_beat;
}
intmax_t Track::getTicksPerBeat() const
{
    return ticks_per_beat_;
}
Track::ConstIteratorType Track:: begin() const
{
//    ConstIteratorType it;
//    it = std::begin(alist);
//    return it;
    return alist.cbegin();
}
Track::ConstIteratorType Track::end() const
{
//    ConstIteratorType it;
//    it = std::end(alist);
//    return it;
    return alist.cend();
}

void Track::addEndEvent(intmax_t tick_time)
{
    //create lists of each event type and put it in? or with the track type list, put everything in it. if so, how do you do that? else create a list of MIDIEvent type?
    // create lists of each event type orded by the tick_time, and put them in a list of track as a nested list?
    ConstIteratorType iter;
    EndTrackEvent endTrackEvent;
    MIDIEvent end1(endTrackEvent, tick_time);
    if (alist.size() ==0)
    {
        alist.push_back(end1);
    }
    else
    {
        int size1 = int(alist.size());
        for (iter = begin(); iter != end(); iter ++ )
        {
            //std::cout<<iter->getTickTime()<<std::endl;
            intmax_t current_t = iter->getTickTime();
            if (current_t >= tick_time)
            {

                alist.insert(iter,end1);
                break;
                //alist.push_back(end1);
            }
        }
        if (int(alist.size()) == size1)
        {
            alist.push_back(end1);
        }
        //std::cout << alist.size() <<std:: endl;
    }


}
void Track::addTempoEvent(intmax_t tempo, intmax_t tick_time)
{
    ConstIteratorType iter;
    TempoEvent tempoEvent(tempo);
    MIDIEvent tempo1(tempoEvent, tick_time);
    if (alist.size() == 0)
    {
        alist.push_back(tempo1);
    }
    else
    {
        int size1 = int(alist.size());
        for (iter = begin(); iter != end(); iter ++ )
        {
            intmax_t current_t = iter->getTickTime();
            if (current_t > tick_time)
            {
                alist.insert(iter,tempo1);
                break;

            }
        }
        if (int(alist.size()) == size1)
        {
            alist.push_back(tempo1);
        }
    }


}
void Track::addNoteEvent(uint8_t code, uint8_t data1, uint8_t data2, intmax_t tick_time)
{
    ConstIteratorType iter;
    bool on_off;
    if (code == 8 || data2 == 0)
        on_off = false;
    else if (code == 9 && data2 != 0)
        on_off = true;
    else{return;}
    NoteEvent noteEvent(on_off, data1, data2);
    MIDIEvent note (noteEvent, tick_time);
    if (alist.size() == 0)
    {
        alist.push_back(note);
    }
    else
    {
        int size1 = int(alist.size());
        for (iter = begin(); iter != end(); iter ++ )
        {
            intmax_t current_t = iter->getTickTime();
            if (current_t >= tick_time)
            {
                alist.insert(iter,note);
                break;

            }
        }
        if (int(alist.size()) == size1)
        {
            alist.push_back(note);
        }
    }

}
