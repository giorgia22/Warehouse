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
      if(EEPROM[l]<10)
        matrix[i][j] = EEPROM[l];
      else
        matrix[i][j] = 0;
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
  display.printModality();
  unsigned int mod=2;
  while(mod>1)
    mod=numberPad.readKey();
  return mod;
}

void Warehouse::conversionOfMatrix(bool modality, bool oldModality){
  if(modality==MANUAL && oldModality==AUTOMATIC){
    for(int i=0; i<WAREHOUSE_CELLS_X; i++){
      for(int j=0; j<WAREHOUSE_CELLS_Y; j++){
        if(matrix[i][j]!=0)
          matrix[i][j]=1;
      }
    }
  }
  else{
    int ultimoPallet=1;
    for(int i=0; i<WAREHOUSE_CELLS_X; i++){
      for(int j=0; j<WAREHOUSE_CELLS_Y; j++){
        if(matrix[i][j]==1){
          matrix[i][j]=ultimoPallet;
          ultimoPallet++;
        }
      }
    }
  }
}

byte Warehouse::requestReset(){
  
}

void Warehouse::resetMatrix(){
  
}

void Warehouse::initializeMatrix(){
  
}
