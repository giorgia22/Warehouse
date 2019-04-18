
#include <Arduino.h>
#include "stepperMotors.h"

unsigned int button = 4;

StepperMotors motorX(8,9,10,11);

void setup() {
  pinMode(button, INPUT_PULLUP);
  motorX.setUp();
}

void loop() {
  motorX.move(true, 180);
  delay(200);
  motorX.move(false, 180);
  delay(200);
  //while(digitalRead(button)!=0){}
}
