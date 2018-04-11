#include <QTest>

#include <QRadioButton>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QSignalSpy>
#include "qinstrument.hpp"
#include "test_config.hpp"
class TestQInstrument : public QObject {
  Q_OBJECT

private slots:

  void initTestCase();
    //void testButtonPressed();
    void simulateRadioButton();
    void testGetVelocity();
    void testGetAttack();
    void testGetDecay();
    void testGetRelease();
    void write_out();
    //
  
  // TODO: add your tests here
  
private:

  QInstrument widget;
};

void TestQInstrument::write_out()
{
    /*
         midi_input = QLineEdit for midi input
         wav_output = QLineEdit for wav output
         radio1,2 = QRadioButton for radio buttons
     [name]Spin = QDoubleSpinBox for vel, att,dec,rel
         synthesize = QPushButon to synthesize.
         spin->setValue(value)
     */
    
    auto radio1 = widget.findChild<QRadioButton *>("harmonic1");
    auto radio2 = widget.findChild<QRadioButton *>("harmonic2");
    auto releaseSpin = widget.findChild<QDoubleSpinBox *>("release");
    auto decaySpin = widget.findChild<QDoubleSpinBox *>("decay");
    auto attackSpin = widget.findChild<QDoubleSpinBox *>("attack");
    auto velocitySpin = widget.findChild<QDoubleSpinBox *>("velocity");
    auto midi_in = widget.findChild<QLineEdit *>("midi_in");
    auto wav_output = widget.findChild<QLineEdit *>("wav_output");
    auto synthesize = widget.findChild<QPushButton *>("synthesize");
    //std::string fname = TEST_FILE_DIR;
    // both radio buttons are off now since they got turned on while init.
    QTest::mouseClick (radio1, Qt::LeftButton);
    QTest::mouseClick (radio2, Qt::LeftButton);
    velocitySpin->setValue(1000.0);
    attackSpin->setValue(0.0625000);
    decaySpin->setValue(0.050000);
    releaseSpin->setValue(0.050000);
    // for default settings.
    for (int i = 0; i < 5; i++)
    {
        
        
        std:: string fname = TEST_FILE_DIR + "/test0"+std::to_string(i) + ".mid";
        QString qfname = QString::fromStdString(fname);
        //qDebug() << qfname;
        midi_in->setText(qfname);
        //Qstring out = "/home/ubuntu/tests";
        wav_output->setText("/home/ubuntu/tests");
        synthesize->click();
        //TURN RADIO1 ON
        QTest::mouseClick (radio1, Qt::LeftButton);
        synthesize->click();
        // TURN BOTH ON
        QTest::mouseClick (radio2, Qt::LeftButton);
        synthesize->click();
        //TURN RADIO1 OFF AND RADIO2 ON
        QTest::mouseClick (radio1, Qt::LeftButton);
        synthesize->click();
        
    }
    
    //for test04 longer
    QTest::mouseClick (radio1, Qt::LeftButton);
    attackSpin->setValue(0.25);
    decaySpin->setValue(0.2);
    releaseSpin->setValue(0.2);
    synthesize->click();
    
    //test_velocity
    attackSpin->setValue(0.0625);
    decaySpin->setValue(0.05);
    releaseSpin->setValue(0.05);
    velocitySpin->setValue(4000.0);
    QTest::mouseClick (radio2, Qt::LeftButton);
    QTest::mouseClick (radio1, Qt::LeftButton);
    synthesize->click();
}
//void TestQInstrument::testButtonPressed()
//{
//
//    auto midi_browse = widget.findChild<QPushButton *>("synthesize");
//    QVERIFY (midi_browse != nullptr);
//    if (midi_browse)
//    {
//        QTest::mouseClick (midi_browse, Qt::LeftButton);
//        QSignalSpy spy(midi_browse, SIGNAL(clicked()));
//        QCOMPARE(spy.isValid(), true);
//
////        QVERIFY( false == QObject::connect(midi_browse, SIGNAL(clicked()), &widget, SLOT(browse_midi()), Qt::UniqueConnection)  );
//
//    }
//}
//Test attack Functions. Also test signal for attack, setAttack()
void TestQInstrument::testGetRelease()
{
    auto releaseSpin = widget.findChild<QDoubleSpinBox *>("release");
    QVERIFY(releaseSpin != nullptr);
    releaseSpin->setValue(0.03);
    QVERIFY( false == QObject::connect(releaseSpin, SIGNAL(valueChanged(double)), &widget, SLOT(setRelease()), Qt::UniqueConnection)  );
    QVERIFY(widget.getRelease() == 0.03);
}
void TestQInstrument::testGetDecay()
{
    auto decaySpin = widget.findChild<QDoubleSpinBox *>("decay");
    QVERIFY(decaySpin != nullptr);
    decaySpin->setValue(0.052);
    QVERIFY( false == QObject::connect(decaySpin, SIGNAL(valueChanged(double)), &widget, SLOT(setDecay()), Qt::UniqueConnection)  );
    QVERIFY(widget.getDecay() == 0.052);
}
void TestQInstrument::testGetAttack()
{
    auto attackSpin = widget.findChild<QDoubleSpinBox *>("attack");
    QVERIFY(attackSpin != nullptr);
    attackSpin->setValue(0.061);
    QVERIFY( false == QObject::connect(attackSpin, SIGNAL(valueChanged(double)), &widget, SLOT(setAttack()), Qt::UniqueConnection)  );
    QVERIFY(widget.getAttack() == 0.061);
}
//Test velocity functions. Also test signal for velocity, setVelocity().
void TestQInstrument::testGetVelocity()
{
    auto velocitySpin = widget.findChild<QDoubleSpinBox *>("velocity");
    QVERIFY(velocitySpin != nullptr);
    velocitySpin->setValue(2000);
    QVERIFY( false == QObject::connect(velocitySpin, SIGNAL(valueChanged(double)), &widget, SLOT(setVelocity()), Qt::UniqueConnection)  );
    QVERIFY(widget.getVelocity() == 2000);
}
//Test radio functions
void TestQInstrument::simulateRadioButton()
{
    auto radio1 = widget.findChild<QRadioButton *>("harmonic1");
    auto radio2 = widget.findChild<QRadioButton *>("harmonic2");
    if (radio1)
    {
        QTest::mouseClick (radio1, Qt::LeftButton);
        bool a = widget.statusRadio1();
        QVERIFY(a == true);
    }
    if (radio2)
    {
        QTest::mouseClick (radio2, Qt::LeftButton);
        bool b = widget.statusRadio2();
        QVERIFY (b == true);
    }
}
// locate all widgets!
void TestQInstrument::initTestCase()
{

  {
    auto w = widget.findChild<QRadioButton *>("harmonic1");
    QVERIFY2(w, "Could not find first harmonic button");
  }

  {
    auto w = widget.findChild<QRadioButton *>("harmonic2");
    QVERIFY2(w, "Could not find second harmonic button");
  }

  {
    auto w = widget.findChild<QDoubleSpinBox *>("velocity");
    QVERIFY2(w, "Could not find velocity edit widget");
  }

  {
    auto w = widget.findChild<QDoubleSpinBox *>("attack");
    QVERIFY2(w, "Could not find attack edit widget");
  }
  
  {
    auto w = widget.findChild<QDoubleSpinBox *>("decay");
    QVERIFY2(w, "Could not find decay edit widget");
  }
  
  {
    auto w = widget.findChild<QDoubleSpinBox *>("release");
    QVERIFY2(w, "Could not find release edit widget");
  }


  {
    auto w = widget.findChild<QLineEdit *>("midi_in");
    QVERIFY2(w, "Could not find a QLineEdit widget");
  }

  {
    auto w = widget.findChild<QLineEdit *>("wav_output");
    QVERIFY2(w, "Could not find a QLineEdit widget");
  }

  {
    auto w = widget.findChild<QPushButton *>("synthesize");
    QVERIFY2(w, "Could not find synthesizer button");
  }
   
    {
        auto w = widget.findChild<QGridLayout *>("grid");
        QVERIFY2(w, "Could not find grid layout");
    }
    {
        auto w = widget.findChild<QGroupBox *>("groupBox1");
        QVERIFY2(w, "could not find groupBox1");
    }
    {
        auto w = widget.findChild<QGroupBox *>("groupBox2");
        QVERIFY2(w, "could not find groupBox2");
    }


    {
        
        auto w = widget.findChild<QGroupBox *>("groupBox3");
        QVERIFY2(w, "could not find groupBox3");
    }
    {
        auto w = widget.findChild<QHBoxLayout *>("hbox1");
        QVERIFY2(w, "could not find hbox1");
    }
    {
        auto w = widget.findChild<QHBoxLayout *> ("l1");
        QVERIFY2(w, "could not find l1");
    }
    {
        auto w = widget.findChild<QHBoxLayout *> ("l2");
        QVERIFY2(w, "could not find l2");
    }
    {
        auto w = widget.findChild<QHBoxLayout *> ("l3");
        QVERIFY2(w, "could not find l3");
    }
    {
        auto w = widget.findChild<QHBoxLayout *> ("l4");
        QVERIFY2(w, "could not find l4");
    }
    {
        auto w = widget.findChild<QVBoxLayout *> ("mainLayout");
        QVERIFY2(w, "could not find mainLayout");
    }
    {
        auto w = widget.findChild<QHBoxLayout *> ("hbox2");
        QVERIFY2(w, " could not find hbox2");
    }
    {
        auto w = widget.findChild<QPushButton *> ("midi_browse");
        QVERIFY2(w, "could not find midi_browse");
    }
    {
        auto w = widget.findChild<QHBoxLayout *> ("hbox3");
        QVERIFY2(w, "could not find hbox3");
    }
    {
        auto w = widget.findChild<QPushButton *> ("wav_browse");
        QVERIFY2(w, "could not find wav_browse");
    }
    
    
    
}

QTEST_MAIN(TestQInstrument)
#include "test_qinstrument.moc"
