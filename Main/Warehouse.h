#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <Arduino.h>
#include <EEPROM.h>
#include "definitions.h"
#include "NumberPad.h"
#include "StepperMotor.h"
#include "Moviment.h"
#include "Display.h"

class Warehouse {
public:
    Warehouse ();
    void begin ();
    void draw();
    void downloadEEPROM();
    void uploadEEPROM();
    void move (byte direction, float degrees);
    byte request(byte variable);
    void conversionOfMatrix(bool modality, bool oldModality);
    void resetMatrix();
    void initializeMatrix();
    void moveToStart();
    void storePallet(byte actualCell[2], byte destinationCell[2], byte numPallet);
    void getPallet(byte actualCell[2], byte destinationCell[2]);
    bool isCellEmpty(byte cell[2]);
    byte getRow();
    byte getColumn();
    void print(byte variable);
    byte startMenu();

private:
    byte numberPadPins[7]={NUMBER_PAD_A_PIN, NUMBER_PAD_B_PIN, NUMBER_PAD_C_PIN, NUMBER_PAD_D_PIN, NUMBER_PAD_E_PIN, NUMBER_PAD_F_PIN, NUMBER_PAD_G_PIN};
    NumberPad numberPad = NumberPad(numberPadPins);
    Display display;
    Moviment moviment;
    
    int matrix[WAREHOUSE_CELLS_X][WAREHOUSE_CELLS_Y];
    byte firstCellFree[2]={0, 3};
    byte lastCellFull[2]={3, 3};
    byte loadCell[2]={0, 3};
    byte unloadCell[2]={1, 3};
};

#endif
