#include "StepperMotors.h"

StepperMotors::StepperMotors(byte phase1, byte phase2, byte phase3, byte phase4) {
    this->phase1 = phase1;
    this->phase2 = phase2;
    this->phase3 = phase3;
    this->phase4 = phase4;
}

void StepperMotors::setUp() {
    pinMode(phase1, OUTPUT);
    pinMode(phase2, OUTPUT);
    pinMode(phase3, OUTPUT);
    pinMode(phase4, OUTPUT);
}

void StepperMotors::write(bool p1, bool p2, bool p3, bool p4){
    digitalWrite (phase1, p1);
    digitalWrite (phase2, p2);
    digitalWrite (phase3, p3);
    digitalWrite (phase4, p4);
}

void StepperMotors::move(bool orientation, float degrees) {
    unsigned int array[4]={0,0,0,0};
    if(!orientation){
        for(float i=0; i<degrees; i+=7.2){
            for(unsigned int j=0; j<4; j++){
              for(unsigned int l=0; l<4; l++) array[l]=0;
              array[j] = 1;
              write(array[0],array[1],array[2],array[3]);
              delay(timeDelay);
            }
        }
    }
    else{
        for(float i=0; i<degrees; i+=7.2){
            for (int j=3; j>0 || j==0;j--){
              for(unsigned int l=0; l<4; l++) array[l]=0;
              array[j] = 1;
              write(array[0],array[1],array[2],array[3]);
              delay(timeDelay);
            }
        }
    }
}


void StepperMotors::moveCm(bool orientation, float centimeters) {
    int degreesCm = 180*centimeters/cm180degrees;
    move(orientation, degreesCm);
}
