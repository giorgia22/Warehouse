#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>

class StepperMotor {
public:
    StepperMotor (byte phase1, byte phase2, byte phase3, byte phase4);
    void begin ();
    void move (bool orientation, float degrees);
    void moveCm(bool orientation, float centimeters);

    

private:
    byte phase1, phase2, phase3, phase4;
    unsigned int timeDelay=17;
    float cm180degrees=1.9;

    void write (bool p1, bool p2, bool p3, bool p4);
};

#endif
