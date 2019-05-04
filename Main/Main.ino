
#include <Arduino.h>
#include "StepperMotor.h"
#include "Warehouse.h"
byte array[4]={H_BRIDGE1_PH1_PIN, H_BRIDGE1_PH2_PIN, H_BRIDGE1_PH3_PIN, H_BRIDGE1_PH4_PIN};
StepperMotor motorX = StepperMotor(array);

void setup() {
  motorX.begin();
}

void loop() {
  motorX.move(true, 180);
  delay(200);
  motorX.move(false, 180);
  delay(200);
}
