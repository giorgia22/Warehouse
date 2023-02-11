#include "Warehouse.h"

Warehouse::Warehouse() {
}

void Warehouse::begin() {
  display.begin();
  print(PRINT_BEGIN);
  numberPad.begin();
  movement.begin();
  movement.actuator(false, true);
  delay(TIME_ACTUATOR);
  movement.actuator(false, false);
  lox.begin();
  downloadEEPROM();
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
  movement.move(direction, degrees);
}


void Warehouse::conversionOfMatrix(bool mode){
  if(mode == MANUAL){
    for(int i = 0; i < WAREHOUSE_CELLS_X; i++){
      for(int j = 0; j < WAREHOUSE_CELLS_Y; j++){
        if(matrix[i][j] != 0)
          matrix[i][j] = 1;
      }
    }
  }
  else if(mode== AUTOMATIC){
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

void Warehouse::print(byte variable){
  display.clear();
  display.print(variable);
}

byte Warehouse::request(byte variable){
  display.clear();
  
  if(variable == PRINT_RESET || variable == PRINT_ROW || variable == PRINT_COLUMN || variable == PRINT_PALLET)  draw();
  display.print(variable);
  
  int limit;
  switch (variable){
    case PRINT_MODE:
      limit = 4;
      break;
      
    case PRINT_RESET:
      limit = 3;
      break;

    case(PRINT_SIMULATION):
      limit = 2;
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
  while(var > (limit-1) && var != 10){
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

void Warehouse::initializeMatrix(byte mod){
  moveToStart();
  movement.move(UP, 200);
  byte from[2], to[2]={0, 3};
  for(int i=0; i<9; i++) {
      from[0] = to[0];
      from[1] = to[1];

      to[0] = i/3;
      if (to[0]%2==1) to[1] = i%3;
      else to[1] = 2 - i%3;
      
      movement.moveBetweenCells(from, to);
      matrix[to[0]][to[1]] = isPalletHere();
      draw();
  }
  conversionOfMatrix(mod);
  movement.move(DOWN, 200);
  optimize();
}

void Warehouse::moveToStart(){
  movement.moveToStart();
  movement.move(RIGHT, 110);
}


void Warehouse::storePallet(byte actualCell[2], byte destinationCell[2], byte numPallet, bool simulation){
  if(!simulation){
    movement.moveBetweenCells(actualCell, loadCell);
    delay(500);
    movement.pickPallet(UP);
    delay(500);
    print(PRINT_DEPOSITO);
    movement.moveBetweenCells(loadCell, destinationCell);
    delay(500);
    movement.pickPallet(DOWN);
    delay(500);
    movement.moveBetweenCells(destinationCell, loadCell);
  }
  matrix[destinationCell[0]][destinationCell[1]] = numPallet;
  draw();
  uploadEEPROM();
}

void Warehouse::getPallet(byte actualCell[2], byte fromCell[2], byte toCell[2], bool simulation){
  if(!simulation){
    movement.moveBetweenCells(actualCell, fromCell);
    delay(200);
    movement.pickPallet(UP);
    delay(200);
    print(PRINT_PRELIEVO);
    movement.moveBetweenCells(fromCell, toCell);
    delay(200);
    movement.pickPallet(DOWN);
    delay(200);
  }
  if(toCell[1] != 3)  matrix[toCell[0]][toCell[1]] = matrix[fromCell[0]][fromCell[1]];
  matrix[fromCell[0]][fromCell[1]] = 0;
  draw();
  uploadEEPROM();
}

bool Warehouse::isCellEmpty(byte cell[2]){
  return (matrix[cell[0]][cell[1]] == 0);
}

void Warehouse::firstCellFreeCoordinates(){
  for(int i = 0; i < 3; i++){
    for(int j = 2; j >= 0; j--){
      if(matrix[i][j] == 0){
        firstCellFree[0] = i;
        firstCellFree[1] = j;
        return;
      }
    }
  }
}

byte Warehouse::getFirstCellFreeRow(){
  firstCellFreeCoordinates();
  return firstCellFree[0];
}

byte Warehouse::getFirstCellFreeColumn(){
  return firstCellFree[1];
}

Menu Warehouse::startMenu(bool oldMode){
  moveToStart();
  myMenu.mode = request(PRINT_MODE);
  delay(200);
  if(myMenu.mode != oldMode)
    conversionOfMatrix(myMenu.mode);
  EEPROM[9] = myMenu.mode;
  byte reset = request(PRINT_RESET);
  delay(200);
  myMenu.initialization = 0;
  switch(reset){
    case(!RESET):
      myMenu.reset = 0;
      break;
      
    case(RESET):
      myMenu.reset = 1;
      resetMatrix();
      break;

    case(INITIALIZATION):
      myMenu.initialization = 1;
      initializeMatrix(myMenu.mode);
      break;

    default:
      break;
  }
  myMenu.simulation = request(PRINT_SIMULATION);
  delay(200);
  return myMenu;
}

bool Warehouse::isPalletHere(){
  int i;
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  int distance = measure.RangeMilliMeter;  
  for(i = 0; i < 10 && distance > DISTANCE_TO_WAREHOUSE; i++){
    movement.move(UP, 10);
    lox.rangingTest(&measure, false);
    distance = measure.RangeMilliMeter;
  }
  movement.move(DOWN, i*10);
  for(i = 0; i < 10 && distance > DISTANCE_TO_WAREHOUSE; i++){
    movement.move(DOWN, 10);
    lox.rangingTest(&measure, false);
    distance = measure.RangeMilliMeter; 
  }
  movement.move(UP, i*10);
  return distance < DISTANCE_TO_WAREHOUSE;
}

void Warehouse::lastCellFullCoordinates(){
  for(int i = 2; i >= 0; i--){
    for(int j = 0; j < 3; j++){
      if(matrix[i][j] != 0) {
        lastCellFull[0] = i;
        lastCellFull[1] = j;
        return;
      }
    }
  }
}

byte Warehouse::getLastCellFullColumn(){
  return lastCellFull[1];
}

byte Warehouse::getLastCellFullRow(){
  lastCellFullCoordinates();
  return lastCellFull[0];
}

byte Warehouse::numPalletInCell(byte cell[2]){
  return matrix[cell[0]][cell[1]];
}

void Warehouse::optimize(){
  firstCellFree[0]=getFirstCellFreeRow();
  firstCellFree[1]=getFirstCellFreeColumn();
  lastCellFull[0]=getLastCellFullRow();
  lastCellFull[1]=getLastCellFullColumn();
  byte actCell[2]={2, 0};
  while(lastCellFull[0] > firstCellFree[0] || lastCellFull[1] < firstCellFree[1]){
    getPallet(actCell, lastCellFull, firstCellFree,0);
    actCell[0] = firstCellFree[0];
    actCell[1] = firstCellFree[1];
    firstCellFree[0]=getFirstCellFreeRow();
    firstCellFree[1]=getFirstCellFreeColumn();
    lastCellFull[0]=getLastCellFullRow();
    lastCellFull[1]=getLastCellFullColumn();
  }
}

bool Warehouse::getOldMode(){
  return EEPROM[9];
}

byte Warehouse::getRowPallet(byte numPallet){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(matrix[i][j]==numPallet)
        return i;
    }
  }
  return 3;
}


byte Warehouse::getColumnPallet(byte numPallet){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(matrix[i][j]==numPallet)
        return j;
    }
  }
  return 3;
}
