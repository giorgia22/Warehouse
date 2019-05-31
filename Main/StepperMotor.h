#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>
#include "definitions.h"

class StepperMotor {
public:
    StepperMotor (byte phasesPins[4]);
    void begin ();
    void move (bool orientation, float degrees);

private:
    byte phasesPins[4];
    unsigned int timeDelay = 4;

    void write (bool phasesValues[4]);
};

#endif
