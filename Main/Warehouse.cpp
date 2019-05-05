#include "Warehouse.h"

Warehouse::Warehouse() {
}

void Warehouse::begin() {
  display.begin();
  numberPad.begin();
  moviment.begin();
  pinMode(FC1_PIN, INPUT_PULLUP);
  pinMode(FC2_PIN, INPUT_PULLUP);
  pinMode(FC3_PIN, INPUT_PULLUP);
  pinMode(FC4_PIN, INPUT_PULLUP);
}

void Warehouse::draw(){
  display.drawWarehouse(DISPLAY_WAREHOUSE_SIDE, matrix);
}

void Warehouse::downloadEEPROM(){
  int l=0;
  for(int i=0; i<WAREHOUSE_CELLS_X; i++){
    for(int j=0; j<WAREHOUSE_CELLS_Y; j++){
      matrix[i][j] = EEPROM[l];
      l++;
    }
  }
}

void Warehouse::uploadEEPROM(){
  int l=0;
  for(int i=0; i<WAREHOUSE_CELLS_X; i++){
    for(int j=0; j<WAREHOUSE_CELLS_Y; j++){
      EEPROM[l] = matrix[i][j];
      l++;
    }
  }
}

void Warehouse::move(byte direction, float degrees){
  moviment.move(direction, degrees);
}

bool Warehouse::requestModality(){
  
}

void Warehouse::conversionOfMatrix(bool modality, bool oldModality){
  
}

byte Warehouse::requestReset(){
  
}

void Warehouse::resetMatrix(){
  
}

void Warehouse::initializeMatrix(){
  
}
