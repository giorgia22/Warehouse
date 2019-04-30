
#include <Arduino.h>
#include <openGLCD.h>
#include "definitions.h"
#include "Warehouse.h"

Warehouse warehouse;

void setup() {
  warehouse.begin();
  warehouse.downloadEEPROM();
  warehouse.draw();
  delay(200);
}

void loop() {
  warehouse.move(RIGHT, 180);
  delay(500);
  warehouse.move(LEFT, 180);
  delay(500);
}
