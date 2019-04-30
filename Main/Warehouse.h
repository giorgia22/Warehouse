#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <Arduino.h>
#include <EEPROM.h>
#include "definitions.h"
#include "Display.h"
#include "Moviment.h"
#include "NumberPad.h"
#include "StepperMotor.h"

class Warehouse {
public:
    Warehouse ();
    void begin ();
    void draw();
    void downloadEEPROM();
    void uploadEEPROM();
    void move(bool orientation, float degrees);

private:
  Display display;
  Moviment moviment;
  
  byte numberPadPins[7] = {NUMBER_PAD_A_PIN, NUMBER_PAD_B_PIN, NUMBER_PAD_C_PIN, NUMBER_PAD_D_PIN, NUMBER_PAD_E_PIN, NUMBER_PAD_F_PIN, NUMBER_PAD_G_PIN};
  NumberPad numberPad = NumberPad (numberPadPins);

  int matrix[WAREHOUSE_CELLS_X][WAREHOUSE_CELLS_Y];
  
};

#endif
