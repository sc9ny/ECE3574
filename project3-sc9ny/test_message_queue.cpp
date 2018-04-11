#include <QTest>

#include "midiplayer.hpp"

class consumer
{
public:
    consumer (message_queue<int> * m)
    {
        mq = m;
    }
    void operator()() const
    {
        for (int i = 0; i < 10; i ++)
        {
            int message = -1;
            mq->wait_and_pop(message);
            QVERIFY2(message == i, "MESSAGE WRONG");
        }
    }
private:
    message_queue<int> *mq = NULL;
};

class producer
{
public:
    producer (message_queue<int> *m)
    {
        mq = m;
    }
    void operator()()const
    {
        for (int i =0; i <10; i++)
        {
            int size = mq->getSize();
            mq->push(i);
            int size1 = mq->getSize();
            QVERIFY2(size+1 == size1, "SIZE WRONG");
            bool empty = mq->empty();
            QVERIFY2(empty == false, "NOT EMPTY");
        }
    }
private:
    message_queue<int> *mq = NULL;
};
class TestMessageQueue :public QObject
{
  Q_OBJECT
    private slots:
    void testMessageQueue();

};
void TestMessageQueue::testMessageQueue()
{
    message_queue <int> mq;
    bool b = mq.empty();
    QVERIFY2(b == true, "NOT EMPTY");
    consumer c(&mq);
    producer p (&mq);
    std::thread consumer_th(c);
    std::thread producer_th(p);
    producer_th.join();
    consumer_th.detach();
    bool empty = mq.empty();
    QVERIFY2(empty == true, "FINAL NOT EMPTY");
}

QTEST_MAIN(TestMessageQueue)
#include "test_message_queue.moc"
