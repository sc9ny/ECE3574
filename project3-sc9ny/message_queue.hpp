/* Adapted from
www.justsoftwaresolutions.co.uk/threading/implementing-a-thread-safe-queue-using-condition-variables.html
*/

#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>
template<typename MessageType>
class message_queue
{
 public:

  void push(MessageType const& message);


  bool empty() const;


  bool try_pop(MessageType& popped_value);

  void stopPressedMQ();
  void wait_and_pop(MessageType& popped_value);
  int getSize();
  void setSampleRate(int sr);
  int getSampleRate();
  //void pauseThread();
  //void resumeThread();
 private:
  std::queue<MessageType> the_queue;
    int sampleRate = 0;
  mutable std::mutex the_mutex;
  std::condition_variable cv;

};

// synthesizer queue
