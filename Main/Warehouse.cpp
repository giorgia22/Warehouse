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


void Warehouse::storePallet(byte actualCell[2], byte destinationCell[2], byte numPallet){
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
  matrix[destinationCell[0]][destinationCell[1]] = numPallet;
  draw();
  uploadEEPROM();
}

void Warehouse::getPallet(byte actualCell[2], byte destinationCell[2]){
  movement.moveBetweenCells(actualCell, destinationCell);
  delay(200);
  movement.pickPallet(UP);
  delay(200);
  print(PRINT_PRELIEVO);
  movement.moveBetweenCells(destinationCell, unloadCell);
  delay(200);
  movement.pickPallet(DOWN);
  delay(200);
  matrix[destinationCell[0]][destinationCell[1]]=0;
  draw();
  uploadEEPROM();
}

bool Warehouse::isCellEmpty(byte cell[2]){
  return (matrix[cell[0]][cell[1]] == 0);
}

byte Warehouse::getRow(){
  byte row = firstCellFree[0];
  if(firstCellFree[1] == 0)
    firstCellFree[0]++;
  return row;
}

byte Warehouse::getColumn(){
  byte column = firstCellFree[1];
  if (column == 0)
    firstCellFree[1] = 2;
  else
    firstCellFree[1]--;
  return column;
}

byte Warehouse::startMenu(){
  Serial.println("...");
  moveToStart();
  Serial.println("...");
  delay(200);
  Serial.println("mod");
  byte mod = request(PRINT_MODALITY);
  delay(200);
  Serial.println("reset");
  byte reset = request(PRINT_RESET);                                         //stampare sul display "scegliere reset: 0.no reset 1.reset(tutto=0) 2.inizz.(spostamento per il magazzino)", aspettare bottone e return
  delay(200);
  if(reset == 1) resetMatrix();                                         //portare a 0 tutte le celle di matrix
  else if(reset == INITIALIZATION) initializeMatrix(mod);  
 
  Serial.println("...");
  return mod;
}

bool Warehouse::isPalletHere(){
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false); 
      
  int distance = measure.RangeMilliMeter; 
      
  for(int i = 0; i < 10 && distance > DISTANCE_TO_WAREHOUSE; i++){
    movement.move(UP, 10);
    distance = measure.RangeMilliMeter; 
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
