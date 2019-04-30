#include "StepperMotor.h"

StepperMotor::StepperMotor(byte phasesPins[4]) {
    for(int i=0; i<4; i++){
      this->phasesPins[i] = phasesPins[i];
    }
}

void StepperMotor::begin() {
    for(int i=0; i<4; i++){
      pinMode(phasesPins[i], OUTPUT);
    }
}

void StepperMotor::write(bool phasesValues[4]){
  for(int i=0; i<4; i++){
    digitalWrite(phasesPins[i], phasesValues[i]);
  }
}

void StepperMotor::move(bool orientation, float degrees) {
    bool array[4]={0,0,0,0};
    if(!orientation){
        for(float i=0; i<degrees; i+=7.2){
            for(unsigned int j=0; j<4; j++){
              for(unsigned int l=0; l<4; l++) array[l]=0;
              array[j] = 1;
              write(array);
              delay(timeDelay);
            }
        }
    }
    else{
        for(float i=0; i<degrees; i+=7.2){
            for (int j=3; j>0 || j==0;j--){
              for(unsigned int l=0; l<4; l++) array[l]=0;
              array[j] = 1;
              write(array);
              delay(timeDelay);
            }
        }
    }
}


void StepperMotor::moveCm(bool orientation, float centimeters) {
    int degreesCm = 180*centimeters/cm180degrees;
    move(orientation, degreesCm);
}
