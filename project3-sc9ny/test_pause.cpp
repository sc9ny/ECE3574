#include <QTest>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>

#include "midiplayer.hpp"

class testPause: public QObject
{
    Q_OBJECT
    
    private slots:
    void testPause123();
private:
    MIDIPlayer widget;
    
};

void testPause::testPause123()
{
    auto w = widget.findChild<QPushButton *>("pause");
    QVERIFY2(w, "Could not find pause button");
}
QTEST_MAIN(testPause)
#include "test_pause.moc"
