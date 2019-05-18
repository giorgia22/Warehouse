#include "Warehouse.h"

Warehouse::Warehouse() {
}

void Warehouse::begin() {
  display.begin();
  print(PRINT_BEGIN);
  numberPad.begin();
  pinMode(FC1_PIN, INPUT_PULLUP);
  pinMode(FC2_PIN, INPUT_PULLUP);
  pinMode(FC3_PIN, INPUT_PULLUP);
  pinMode(FC4_PIN, INPUT_PULLUP);
  moviment.begin();
  
  moviment.actuator(false, true);
  delay(TIME_ACTUATOR);
  moviment.actuator(false, false);
}

void Warehouse::draw(){
  display.drawWarehouse(DISPLAY_WAREHOUSE_SIDE, matrix);
}

void Warehouse::downloadEEPROM(){
  int l = 0;
  for(int i = 0; i < WAREHOUSE_CELLS_X; i++){
    for(int j = 0; j < WAREHOUSE_CELLS_Y; j++){
      if(EEPROM[l] < 10)
        matrix[i][j] = EEPROM[l];
      else
        matrix[i][j] = 0;
      l++;
    }
  }
}

void Warehouse::uploadEEPROM(){
  int l = 0;
  for(int i = 0; i<WAREHOUSE_CELLS_X; i++){
    for(int j = 0; j<WAREHOUSE_CELLS_Y; j++){
      EEPROM[l] = matrix[i][j];
      l++;
    }
  }
}

void Warehouse::move(byte direction, float degrees){
  moviment.move(direction, degrees);
}


void Warehouse::conversionOfMatrix(bool modality, bool oldModality){
  if(modality == MANUAL && oldModality == AUTOMATIC){
    for(int i = 0; i < WAREHOUSE_CELLS_X; i++){
      for(int j = 0; j < WAREHOUSE_CELLS_Y; j++){
        if(matrix[i][j] != 0)
          matrix[i][j] = 1;
      }
    }
  }
  else{
    int ultimoPallet = 1;
    for(int i = 0; i < WAREHOUSE_CELLS_X; i++){
      for(int j = 0; j < WAREHOUSE_CELLS_Y; j++){
        if(matrix[i][j] == 1){
          matrix[i][j] = ultimoPallet;
          ultimoPallet++;
        }
      }
    }
  }
}

void Warehouse::print( byte variable){
  display.clear();
  display.print(variable);
}

byte Warehouse::request(byte variable){
  display.clear();
  
  if(variable == PRINT_RESET || variable == PRINT_ROW || variable == PRINT_COLUMN)  draw();
  display.print(variable);
  
  int limit;
  switch (variable){
    case PRINT_MODALITY:
      limit = 3;
      break;
      
    case PRINT_RESET:
      limit = 3;
      break;
      
    case PRINT_ROW:
      limit = 3;
      break;
      
    case PRINT_COLUMN:
      limit = 3;
      break;
      
    case PRINT_PALLET:
      limit = 10;
      break;
      
    default:
      break;
  }
  
  int var = 12;
  while(var > (limit-1) ){
      var = numberPad.readKey();
  }
  return var;
}

void Warehouse::resetMatrix(){
  for(int i = 0; i < WAREHOUSE_CELLS_X; i++){
      for(int j = 0; j < WAREHOUSE_CELLS_Y; j++){
          matrix[i][j] = 0;
      }
   }
}

void Warehouse::initializeMatrix(){
  
}

void Warehouse::moveToStart(bool area){
  moviment.moveToStart(area);
}


void Warehouse::storePallet(byte actualCell[2], byte destinationCell[2], byte numPallet){
  moviment.moveBetweenCells(actualCell, loadCell);
  delay(500);
  moviment.pickPallet(UP);
  delay(500);
  print(PRINT_DEPOSITO);
  moviment.moveBetweenCells(loadCell, destinationCell);
  delay(500);
  moviment.pickPallet(DOWN);
  delay(500);
  moviment.moveBetweenCells(destinationCell, loadCell);     //sostituire con moveToStart quando ci saranno i finecorsa
  matrix[destinationCell[0]][destinationCell[1]]=numPallet;
  display.clear();
}

void Warehouse::getPallet(byte actualCell[2], byte destinationCell[2]){
  moviment.moveBetweenCells(actualCell, destinationCell);
  delay(200);
  moviment.pickPallet(UP);
  delay(200);
  print(PRINT_PRELIEVO);
  moviment.moveBetweenCells(destinationCell, unloadCell);
  delay(200);
  moviment.pickPallet(DOWN);
  delay(200);
  matrix[destinationCell[0]][destinationCell[1]]=0;
  display.clear();
}

bool Warehouse::isCellEmpty(byte cell[2]){
  return (matrix[cell[0]][cell[1]] == 0);
}

byte Warehouse::getRow(){
  byte row = firstCellFree[0];
  if(row == 2)
    firstCellFree[0] = 0;
  else
    firstCellFree[0]--;
  return row;
}

byte Warehouse::getColumn(){
  byte column = firstCellFree[1];
  if (column == 0)
    firstCellFree[1] = 2;
  else
    firstCellFree[1]++;
  return column;
}
