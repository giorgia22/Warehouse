#ifndef STEPPER_MOTORS_H
#define STEPPER_MOTORS_H

#include <Arduino.h>

class StepperMotors {
public:
    StepperMotors (unsigned int phase1, unsigned int phase2, unsigned int phase3, unsigned int phase4);
    void setUp ();
    void write (bool p1, bool p2, bool p3, bool p4);
    void move (bool orientation, float degrees);
    void moveCm(bool orientation, int centimeters);

    
    unsigned int timeDelay=17;
    const float cm180degrees=1.9;

private:
    unsigned int phase1, phase2, phase3, phase4;
};

#endif
