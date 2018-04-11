#include "shared_double_buffer.hpp"
#include <QDebug>
// Implement your shared double buffer here
template<typename T>
shared_double_buffer<T>::shared_double_buffer(size_t s)
{
    size = s;
}
template<typename T>

bool shared_double_buffer<T>::s_d_b_push(const T &item)
{
    std::unique_lock<std::mutex> lock(the_mutex);

    // if the writing buffer is full
    if (int(the_queue2.size()) ==int(size))
        return false;

    the_queue2.push(item);
    return true;
}
//template<typename T>
//shared_double_buffer<T> & shared_double_buffer<T>::operator =(std::queue<T> const & q)
//{
//    return *this;
//}

template<typename T>
bool shared_double_buffer<T>::empty()
{
    std::lock_guard<std::mutex> lock(the_mutex);
    return the_queue1.empty();
}
template<typename T>
void shared_double_buffer<T>::s_d_b_try_pop( T &item)
{
    //
    if (the_queue1.empty())
    {
        swap();
    }
    else if (!the_queue1.empty())
    {
        std::lock_guard<std::mutex> lock(the_mutex);
        item = the_queue1.front();
        the_queue1.pop();

    }

}
template<typename T>
void shared_double_buffer<T>::s_d_b_wait_and_push(const T &item)
{
    std::unique_lock<std::mutex> lock(the_mutex);
    while (int(the_queue2.size()) == int(size))
    {
        cv.wait(lock);
    }
    the_queue2.push(item);

}
template<typename T>
bool shared_double_buffer<T>::swap()
{
    std::unique_lock<std::mutex> lock(the_mutex);

    the_queue1.swap(the_queue2);

    lock.unlock();
    cv.notify_one();
    return true;
}
template<typename T>
void shared_double_buffer<T>::setBufferSize(size_t s)
{
    std::lock_guard<std::mutex> lock(the_mutex);
    size = s;
}
template<typename T>
int shared_double_buffer<T>::getBufferSize()
{
    return size;
}
template<typename T>
void shared_double_buffer<T>::stopPressed()
{

    std::lock_guard<std::mutex> lock (the_mutex);

    while (!the_queue1.empty())
    {
        the_queue1.pop();
    }
    while (!the_queue2.empty())
    {
      //  qDebug() <<"que2";
        the_queue2.pop();
    }
    //qDebug() << "DONE";
}
//template<typename T>
//void shared_double_buffer<T>::suspend()
//{
//    std::unique_lock<std::mutex> lock (the_mutex);

//    while (flag)
//    {
//        cv.wait(lock);
//    }
//    flag = false;
//}
//template<typename T>
//void shared_double_buffer<T>::quitSuspension()
//{
//    std::unique_lock<std::mutex> lock (the_mutex);
//    flag = false;
//    lock.unlock();
//    cv.notify_one();
//}
template class shared_double_buffer<double>;
template class shared_double_buffer<int16_t>;
