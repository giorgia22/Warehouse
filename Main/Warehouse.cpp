#include "Warehouse.h"

Warehouse::Warehouse() {
}

void Warehouse::begin() {
  display.begin();
  numberPad.begin();
  moviment.begin();
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

void Warehouse::move(bool orientation, float degrees){
  moviment.move(orientation, degrees);
}
