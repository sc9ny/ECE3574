    #include <QTest>
    #include <QPushButton>
    #include <QSlider>
    #include <QLineEdit>
    #include "midiplayer.hpp"

    class testPlayButton : public QObject
    {
      Q_OBJECT

        private slots:
            void testPlay();
        
    private:
        MIDIPlayer widget;
    };

    void testPlayButton::testPlay()
    {
        auto play = widget.findChild<QPushButton *>("play");
        auto input = widget.findChild<QLineEdit *>("inputpath");
        auto stop = widget.findChild<QPushButton *> ("stop");
        input->setText("/vagrant/tests/test6.mid");
        QVERIFY2(play, "could not find play button");
    }
    QTEST_MAIN(testPlayButton)
    #include "test_play.moc"
