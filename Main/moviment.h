#ifndef MOVIMENT_H
#define MOVIMENT_H

#include "StepperMotor.h"
#include "definitions.h"

class Moviment{
public:
    Moviment ();
    void begin();
    void pickUp ();
    void putDown ();
    void moveToCell();
    void moveToArea();
    void move (bool orientation, float degrees);
    void moveCm(bool orientation, float centimeters);

private:
    byte phasesX[4] = {H_BRIDGE1_PH1_PIN, H_BRIDGE1_PH2_PIN, H_BRIDGE1_PH3_PIN, H_BRIDGE1_PH4_PIN};
    byte phasesY[4] = {H_BRIDGE2_PH1_PIN, H_BRIDGE2_PH2_PIN, H_BRIDGE2_PH3_PIN, H_BRIDGE2_PH4_PIN};
    StepperMotor motorX = StepperMotor(phasesX);
    StepperMotor motorY = StepperMotor(phasesY);
};

#endif
