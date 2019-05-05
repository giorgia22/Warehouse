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
    void moveToCell(int row, int column, int actualRow, int actualColumn);
    void moveToArea(bool area);
    void move(byte direction, float degrees);

private:
    byte motorXPins[4]={H_BRIDGE1_PH1_PIN, H_BRIDGE1_PH2_PIN, H_BRIDGE1_PH3_PIN, H_BRIDGE1_PH4_PIN};
    byte motorYPins[4]={H_BRIDGE2_PH1_PIN, H_BRIDGE2_PH2_PIN, H_BRIDGE2_PH3_PIN, H_BRIDGE2_PH4_PIN};
    StepperMotor motorX = StepperMotor(motorXPins);
    StepperMotor motorY = StepperMotor(motorYPins);

    float distancesBetweenCells[5]={DISTANCE_0to1_COLUMN, DISTANCE_1to2_COLUMN, DISTANCE_2to3_COLUMN, DISTANCE_0to1_ROW, DISTANCE_1to2_ROW};

};

#endif
