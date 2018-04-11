#include <QTest>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>

#include "midiplayer.hpp"

class test_stop: public QObject
{
    Q_OBJECT
    
    private slots:
    
    void test_stop123();
private:
    MIDIPlayer widget;
};

void test_stop::test_stop123()
{
    auto w = widget.findChild<QPushButton *> ("stop");
    QVERIFY2(w, "Could not find stop button");
}

QTEST_MAIN(test_stop)
#include "test_stop.moc"
