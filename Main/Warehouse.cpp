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
  Serial.begin(9600);
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
    case PRINT_MODALITY:
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

void Warehouse::initializeMatrix(bool mod){
  moveToStart();
  movement.move(UP, 200);
  byte from[2]={0, 3}, to[2];
  
  for(int i=0; i<3; i++){
    int j = 3;
    if (i == 2) j = 2;
    else if (i == 1) j = 0;
   
    to[0] = i;
    from[1] = j;
    to[1] = j-1;
    
    if(i != 0){
      from[0] = i-1;
      to[1] = j;
    }
    
    for(int mov=0; mov<3; mov++){
      movement.moveBetweenCells(from, to);
      matrix[to[0]][to[1]] = isPalletHere();
      
      from[0] = i;
      delay(200);
      if(i%2 == 0){
        j--;
        from[1] = j;
        to[1] = j-1;
      }
      else{
        j++;
        from[1] = j;
        to[1] = j+1;
      }
    }
  }
  movement.moveBetweenCells(from, to);
  matrix[to[0]][to[1]] = isPalletHere();
  if(mod = AUTOMATIC) conversionOfMatrix(!mod, mod);
  movement.move(DOWN, 500);
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
    movement.moveBetweenCells(destinationCell, loadCell);     //sostituire con moveToStart quando ci saranno i finecorsa
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

struct menu Warehouse::startMenu(bool oldModality){
  moveToStart();
  delay(200);
  Serial.println("mod");
  myMenu.modality = request(PRINT_MODALITY);
  if(myMenu.modality != oldModality && (myMenu.modality == 0 || myMenu.modality == 1))
    conversionOfMatrix(myMenu.modality, oldModality);
  delay(200);
  Serial.println("reset");
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
      initializeMatrix(myMenu.modality);
      break;

    default:
      break;
  }
  Serial.println("sim");
  myMenu.simulation = request(PRINT_SIMULATION);

  return myMenu;
}

bool Warehouse::isPalletHere(){
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false); 
      
  int distance = measure.RangeMilliMeter; 
      Serial.println(distance);
  for(int i = 0; i < 10 && distance > DISTANCE_TO_WAREHOUSE; i++){
    movement.move(UP, 10);
    distance = measure.RangeMilliMeter; 
      Serial.println(distance);
  }
  movement.move(DOWN, 100);
  for(int i = 0; i < 10 && distance > DISTANCE_TO_WAREHOUSE; i++){
    movement.move(DOWN, 10);
    distance = measure.RangeMilliMeter; 
  }
  distance = measure.RangeMilliMeter; 
      
  if(distance < DISTANCE_TO_WAREHOUSE) return 1;
  else return 0;
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
