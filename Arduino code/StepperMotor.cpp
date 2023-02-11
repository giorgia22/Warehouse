#include "StepperMotor.h"

StepperMotor::StepperMotor(byte phasesPins[4]) {
    for(int i = 0; i < 4; i++) this->phasesPins[i] = phasesPins[i];
}

void StepperMotor::begin() {
    for(int i = 0; i < 4; i++) pinMode(phasesPins[i], OUTPUT);
}

void StepperMotor::write(bool phasesValues[4]){
    for(int i = 0; i < 4; i++) digitalWrite (phasesPins[i], phasesValues[i]);
}

void StepperMotor::move(bool orientation, float degrees, byte FC) {
    bool phasesValues[4] = {0,0,0,0};
    int j = 0;
    
    for(float i = 0; i < degrees && analogRead(FC)>800; i+=1.8){
              for(unsigned int l = 0; l < 4; l++) phasesValues[l] = 0;
              phasesValues[abs(3*(int)orientation-j)] = 1;
              
              write(phasesValues);
              delay(timeDelay);
              j++;
              if(j == 4) j = 0;
        }
    for(unsigned int l = 0; l < 4; l++) phasesValues[l] = 0;
    write(phasesValues);
}
