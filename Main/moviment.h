#ifndef MOVIMENT_H
#define MOVIMENT_H

#include <Arduino.h>
#include "StepperMotor.h"
#include "definitions.h"

class Moviment{
public:
    Moviment ();
    void begin();
    void pickPallet (bool direction);
    void moveBetweenCells(byte fromCell[2], byte toCell[2]);
    void move(byte direction, float degrees);
    void actuator(bool pos, bool neg);
    void moveToStart();

private:
    byte motorXPins[4] = {H_BRIDGE1_PH1_PIN, H_BRIDGE1_PH2_PIN, H_BRIDGE1_PH3_PIN, H_BRIDGE1_PH4_PIN};
    byte motorYPins[4] = {H_BRIDGE2_PH1_PIN, H_BRIDGE2_PH2_PIN, H_BRIDGE2_PH3_PIN, H_BRIDGE2_PH4_PIN};
    StepperMotor motorX = StepperMotor(motorXPins);
    StepperMotor motorY = StepperMotor(motorYPins);

    float horizontalDistances[3] = {DISTANCE_0to1_COLUMN, DISTANCE_1to2_COLUMN, DISTANCE_2to3_COLUMN};
    float verticalDistances[2] = {DISTANCE_0to1_ROW, DISTANCE_1to2_ROW};

    float distance(bool direction, byte a, byte b);

    byte loadCell[2] = {0, 3};
    byte unloadCell[2] = {1, 3};
    
};

#endif
