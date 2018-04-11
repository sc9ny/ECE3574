
#include <QTest>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>

#include "midiplayer.hpp"

class test_resume: public QObject
{
    Q_OBJECT
    private slots:
    
    void test_resume123();
private:
    MIDIPlayer widget;
};

void test_resume::test_resume123()
{
    auto w = widget.findChild<QPushButton *> ("play");
    QVERIFY2(w, "Could not find play button");
    
}
QTEST_MAIN(test_resume)
#include "test_resume.moc"
