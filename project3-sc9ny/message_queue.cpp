#include "message_queue.hpp"
#include <QDebug>
//Implement your message queue here
template<typename MessageType>
void message_queue<MessageType>::push(MessageType const& message)
{

    std::unique_lock<std::mutex> lock(the_mutex);
    the_queue.push(message);
    lock.unlock();
    cv.notify_one();
}
template<typename MessageType>
bool message_queue<MessageType>:: empty() const
{
    std::lock_guard<std::mutex> lock(the_mutex);
    return the_queue.empty();
}
template<typename MessageType>
bool message_queue<MessageType>::try_pop(MessageType& popped_value)
{

    std::lock_guard<std::mutex> lock(the_mutex);
    if(the_queue.empty())
    {
        return false;
    }

    popped_value=the_queue.front();
    the_queue.pop();
    return true;
}
template<typename MessageType>
void message_queue<MessageType>::wait_and_pop(MessageType& popped_value)
{
    std::unique_lock<std::mutex> lock(the_mutex);
    while(the_queue.empty())
    {

        cv.wait(lock);
    }

    popped_value=the_queue.front();
    the_queue.pop();
}
//template<typename MessageType>
//void message_queue<MessageType>::pauseThread()
//{
//    qDebug() << "PAUSE";
//    pause = true;
//    std::unique_lock<std::mutex> lock(the_mutex);
//    while(pause)
//    {
//        cv.wait(lock);
//    }
//}
//template<typename MessageType>
//void message_queue<MessageType>::resumeThread()
//{
//    std::unique_lock<std::mutex> lock(the_mutex);
//    pause =false;
//    lock.unlock();
//    cv.notify_one();
//}
template<typename MessageType>
int message_queue<MessageType>::getSize()
{
    return the_queue.size();
}
template<typename MessageType>
void message_queue<MessageType>::stopPressedMQ()
{
    while(the_queue.size() != 0)
    {
        the_queue.pop();
    }
}
template<typename MessageType>
void message_queue<MessageType>::setSampleRate(int sr)
{
    std::unique_lock<std::mutex> lock (the_mutex);
    sampleRate =sr;
    //qDebug() <<"NOTIIED";
    lock.unlock();
    cv.notify_one();

}
template<typename MessageType>
int message_queue<MessageType>::getSampleRate()
{
    std::unique_lock<std::mutex> lock (the_mutex);
    while (sampleRate == 0)
    {
        //qDebug() << "WAITING";
        cv.wait(lock);
    }

    return sampleRate;
}
template class message_queue<std::string>;
template class message_queue<int>;
