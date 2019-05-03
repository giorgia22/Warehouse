#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>

class StepperMotor {
public:
    StepperMotor (byte phasesPins[4]);
    void begin ();
    void move (bool orientation, float degrees);
    void moveCm(bool orientation, float centimeters);

    

private:
    byte phasesPins[4];
    int actualPhase=0;
    unsigned int timeDelay=17;
    float cm180degrees=1.9;

    void write (bool phasesValues[4]);
};

#endif
