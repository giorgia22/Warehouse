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
    digitalWrite(phasesPins[0], 1);
    digitalWrite(phasesPins[1], 0);
    digitalWrite(phasesPins[2], 0);
    digitalWrite(phasesPins[3], 0);
}

void StepperMotor::write(bool phasesValues[4]){
  for(int i=0; i<4; i++){
    digitalWrite(phasesPins[i], phasesValues[i]);
  }
}

void StepperMotor::move(bool orientation, float degrees) {
    bool array[4]={0,0,0,0};
    if(!orientation){
        for(float i=0; i<degrees; i+=1.8){
              for(unsigned int l=0; l<4; l++) array[l]=0;
              array[actualPhase] = 1;
              write(array);
              actualPhase++;
              if(actualPhase==4) actualPhase=0;
              delay(timeDelay);
        }
    }
    else{
        for(float i=0; i<degrees; i+=1.8){
              for(unsigned int l=0; l<4; l++) array[l]=0;
              array[actualPhase] = 1;
              write(array);
              actualPhase--;
              if(actualPhase==-1) actualPhase=3;
              delay(timeDelay);
        }
    }
}


void StepperMotor::moveCm(bool orientation, float centimeters) {
    int degreesCm = 180*centimeters/cm180degrees;
    move(orientation, degreesCm);
}
