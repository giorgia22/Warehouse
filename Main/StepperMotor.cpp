#include "StepperMotor.h"

StepperMotor::StepperMotor(byte phasesPins[4]) {
    for(int i = 0; i < 4; i++) this->phasesPins[i] = phasesPins[i];
}

void StepperMotor::begin() {
    for(int i = 0; i < 4; i++) pinMode(phasesPins[i], OUTPUT);
    pinMode(FC1_PIN, INPUT_PULLUP);
    pinMode(FC2_PIN, INPUT_PULLUP);
    pinMode(FC3_PIN, INPUT_PULLUP);
    pinMode(FC4_PIN, INPUT_PULLUP);
}

void StepperMotor::write(bool phasesValues[4]){
    for(int i = 0; i < 4; i++) digitalWrite (phasesPins[i], phasesValues[i]);
}

void StepperMotor::move(bool orientation, float degrees) {
    bool phasesValues[4] = {0,0,0,0};
    int j = 0;
    byte FC;
    switch(orientation){
      case (UP):
          FC = FC4_PIN;
          break;
      case (DOWN):
          FC = FC3_PIN;
          break;
      case (LEFT):
          FC = FC1_PIN;
          break;
      case (RIGHT):
          FC = FC2_PIN;
          break;
    }
    
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
