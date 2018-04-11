#ifndef QINSTRUMENT_HPP
#define QINSTRUMENT_HPP
#include <QWidget>
#include <QLineEdit>
#include <string>
#include <QGroupBox>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QRadioButton>
#include "signal.hpp"
#include "track.hpp"
#include "interactive_instrument.hpp"
#include "midi.hpp"
#include "wav.hpp"
// TODO
class QInstrument : public QWidget {
    Q_OBJECT
public:
    QInstrument(QWidget *parent =0);
    double getVelocity();
    double getAttack();
    double getDecay();
    double getRelease();
    double getMidi_input();
    double getWav_output();
    bool statusRadio1();
    bool statusRadio2();
    
    
    std::string getMidi_in();
    std::string getWav_out();
    
    private slots:
    void browse_midi();
    void browse_wav();
    void setVelocity();
    void setAttack();
    void setDecay();
    void setRelease();
    bool radio1Status();
    bool radio2Status();
    void write_out();
    //Signal synthesizer();
private:
    //Track track;
    std::string midi_in ="";
    std::string wav_out= "";
    std::string prev = "";
    bool radio1Checked = false;
    bool radio2Checked = false;
    double velocity = 1000;
    double attack = 0.062500;
    double decay = 0.05;
    double release = 0.05;
    //InteractiveInstrument inst;
    // Private Functions.
    int outNum = 0;
    
    //GUI PART
    QLineEdit* midi_input;
    QLineEdit* wav_output;
    QGroupBox* createFirstBox();
    QGroupBox* createSecondBox();
    QGroupBox* createThirdBox();
    QPushButton* midi_browse;
    QPushButton* wav_browse;
    QPushButton * synthesize;
    QDoubleSpinBox *releaseSpin;
    QDoubleSpinBox *decaySpin;
    QDoubleSpinBox *attackSpin;
    QDoubleSpinBox *velocitySpin;
    QRadioButton *radio1;
    QRadioButton *radio2;
    
    
};
//Exercise 11 is a starting point
// what data fields are needed?
// QRadioButtons, QDoubleSpinBoxes, QLineEdits,

//Constructor hierarchically builds the window

// What signals and slots are needed?
// - synthesize all tracks when the Synthesize button is pressed.
// - queries the value/state of widgets
// - similar to MS1 main()
// - calls a funtion to synthsize one track
// - this function instantiates an InterativeInstrument much like MS1 synthesize()
// All widgets can be assigned an objectName property

//Look at QFormLayouts and QGroupBoxes


#endif

