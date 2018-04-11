// Define your shared double buffer here
#include <queue>
#include <mutex>
#include <condition_variable>
template <typename T>
class shared_double_buffer
{
public:
    shared_double_buffer(size_t s =1024);
    bool s_d_b_push(T const& item);
    bool empty();
    void s_d_b_try_pop(T & item);
    void s_d_b_wait_and_push( T const& item);
    bool swap();
    void setBufferSize(size_t s);
    int getBufferSize();
    void stopPressed();
    void suspend();
    void quitSuspension();
//    void pauseThread();
//    void resumeThread();
    //shared_double_buffer &operator= (std::queue<T> const & q);
private:
    std::queue<T> the_queue1;
    std::queue<T> the_queue2;
    mutable std::mutex the_mutex;
    std::condition_variable cv;
    bool flag = false;
    size_t size;
    //bool pause = false;
};
