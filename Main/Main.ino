
#include <Arduino.h>
#include "StepperMotor.h"
#include "Warehouse.h"

StepperMotor motorX((byte)H_BRIDGE1_PH1_PIN, (byte)H_BRIDGE1_PH2_PIN, (byte)H_BRIDGE1_PH3_PIN, (byte)H_BRIDGE1_PH4_PIN);

void setup() {
  motorX.begin();
}

void loop() {
  motorX.move(true, 180);
  delay(200);
  motorX.move(false, 180);
  delay(200);
}
