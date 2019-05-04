#ifndef MOVIMENT_H
#define MOVIMENT_H

#include <Arduino.h>
#include "StepperMotor.h"
#include "definitions.h"

class Moviment{
public:
    Moviment ();
    void begin();
    void pickUp ();
    void putDown ();
    void moveToCell(int row, int column);
    void moveToArea(bool area);
    void move(bool orientation, float degrees);

private:
    //byte motorXPins[4]={H_BRIDGE1_PH1_PIN, H_BRIDGE1_PH2_PIN, H_BRIDGE1_PH3_PIN, H_BRIDGE1_PH4_PIN};
    //byte motorYPins[4]={H_BRIDGE2_PH1_PIN, H_BRIDGE2_PH2_PIN, H_BRIDGE2_PH3_PIN, H_BRIDGE2_PH4_PIN};
    StepperMotor motorX = StepperMotor(H_BRIDGE1_PH1_PIN, H_BRIDGE1_PH2_PIN, H_BRIDGE1_PH3_PIN, H_BRIDGE1_PH4_PIN);
    StepperMotor motorY = StepperMotor(H_BRIDGE2_PH1_PIN, H_BRIDGE2_PH2_PIN, H_BRIDGE2_PH3_PIN, H_BRIDGE2_PH4_PIN);

};

#endif
