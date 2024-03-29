#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <Arduino.h>
#include <EEPROM.h>
#include "definitions.h"
#include "NumberPad.h"
#include "StepperMotor.h"
#include "movement.h"
#include "Display.h"
#include "Adafruit_VL53L0X.h"



struct Menu{
  byte mode;
  bool reset;
  bool initialization;
  bool simulation;
};


class Warehouse {
public:
    Warehouse ();
    void begin ();
    void draw();
    void move (byte direction, float degrees);
    byte request(byte variable);
    void conversionOfMatrix(bool mode);
    void resetMatrix();
    void initializeMatrix(byte mod);
    void moveToStart();
    void storePallet(byte actualCell[2], byte destinationCell[2], byte numPallet, bool simulation);
    void getPallet(byte actualCell[2], byte fromCell[2], byte toCell[2], bool simulation);
    bool isCellEmpty(byte cell[2]);
    byte getFirstCellFreeRow();
    byte getFirstCellFreeColumn();
    void print(byte variable);
    Menu startMenu(bool oldMode);
    byte getLastCellFullColumn();
    byte getLastCellFullRow();
    byte numPalletInCell(byte cell[2]);
    void optimize();
    bool getOldMode();
    byte getRowPallet(byte numPallet);
    byte getColumnPallet(byte numPallet);

private:
    byte numberPadPins[7]={NUMBER_PAD_A_PIN, NUMBER_PAD_B_PIN, NUMBER_PAD_C_PIN, NUMBER_PAD_D_PIN, NUMBER_PAD_E_PIN, NUMBER_PAD_F_PIN, NUMBER_PAD_G_PIN};
    NumberPad numberPad = NumberPad(numberPadPins);
    Display display;
    Movement movement;
    Adafruit_VL53L0X lox = Adafruit_VL53L0X();
    
    int matrix[WAREHOUSE_CELLS_X][WAREHOUSE_CELLS_Y];
    byte firstCellFree[2];
    byte lastCellFull[2];
    byte loadCell[2]={0, 3};
    byte unloadCell[2]={1, 3};

    Menu myMenu;

    bool isPalletHere();
    void firstCellFreeCoordinates();
    void lastCellFullCoordinates();
    void downloadEEPROM();
    void uploadEEPROM();
};

#endif
