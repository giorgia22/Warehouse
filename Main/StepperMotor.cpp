#include "StepperMotor.h"

StepperMotor::StepperMotor(byte phase1, byte phase2, byte phase3, byte phase4) {
    this->phase1 = phase1;
    this->phase2 = phase2;
    this->phase3 = phase3;
    this->phase4 = phase4;
}

void StepperMotor::begin() {
    pinMode(phase1, OUTPUT);
    pinMode(phase2, OUTPUT);
    pinMode(phase3, OUTPUT);
    pinMode(phase4, OUTPUT);
}

void StepperMotor::write(bool p1, bool p2, bool p3, bool p4){
    digitalWrite (phase1, p1);
    digitalWrite (phase2, p2);
    digitalWrite (phase3, p3);
    digitalWrite (phase4, p4);
}

void StepperMotor::move(bool orientation, float degrees) {
    unsigned int array[4]={0,0,0,0};
    int j=0;
    if(!orientation){
      
        for(float i=0; i<degrees; i+=1.8){
              for(unsigned int l=0; l<4; l++) array[l]=0;
              array[j] = 1;
              write(array[0],array[1],array[2],array[3]);
              delay(timeDelay);
              j++;
              if(j==4) j=0;
        }
    }
    else{
        for(float i=0; i<degrees; i+=1.8){
              for(unsigned int l=0; l<4; l++) array[l]=0;
              array[3-j] = 1;
              write(array[0],array[1],array[2],array[3]);
              delay(timeDelay);
              j++;
              if(j==4) j=0;
        }
    }
}


void StepperMotor::moveCm(bool orientation, float centimeters) {
    int degreesCm = 180*centimeters/cm180degrees;
    move(orientation, degreesCm);
}
