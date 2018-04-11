
#include <QTest>
#include "midiplayer.hpp"

class consumer
{
public:
    consumer (shared_double_buffer<double> * d)
    
    {
        db = d;
    }
    void operator()() const
    {
        for (int i =0; i < 10; i++)
        {
            
            double message = -1;
            if (!db->empty())
            {
                db->s_d_b_try_pop(message);
                QVERIFY2(message == i, "MESSAGE WRONG");
            }
            
            
        }
    }
    
private:
    shared_double_buffer<double> *db= NULL;
};
class producer
{
public:
    producer(shared_double_buffer<double> *d)
    {
        db = d;
    }
    void operator()() const
    {
        for (int i =0; i < 10; i++)
        {
            bool a = db->s_d_b_push(i);
            QVERIFY2(a == true, "NOT PUSHED");
        }
    }
private:
    shared_double_buffer<double> *db = NULL;
};

class TestDoubleBuffer : public QObject
{
    Q_OBJECT
    
    private slots:
    void testDoubleBuffer();
    
private:
    int message = -1;
    shared_double_buffer<double> *db;
};

void TestDoubleBuffer::testDoubleBuffer()
{
    shared_double_buffer<double> db(1024);
    db.setBufferSize(2048);
    int j = db.getBufferSize();
    QVERIFY2(j == 2048, "SIZE WRONG");
    consumer c(&db);
    producer p(&db);
    std::thread consumer_th(c);
    std::thread producer_th(p);
    
    producer_th.join();
    consumer_th.join();
    bool empty = db.empty();
    QVERIFY2(empty == true, "NOT EMPTY");
}
QTEST_MAIN(TestDoubleBuffer)
#include "test_double_buffer.moc"
