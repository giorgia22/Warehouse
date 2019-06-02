#include <Arduino.h>
#include <EEPROM.h>
#include "Warehouse.h"
#include "movement.h"
#include "NumberPad.h"

movement movement;
byte numberPadPins[7]={NUMBER_PAD_A_PIN, NUMBER_PAD_B_PIN, NUMBER_PAD_C_PIN, NUMBER_PAD_D_PIN, NUMBER_PAD_E_PIN, NUMBER_PAD_F_PIN, NUMBER_PAD_G_PIN};
NumberPad numberPad = NumberPad(numberPadPins);

byte oldModality;
byte num;
byte actualCell[2]={0, 3}, destinationCell[2];
byte unloadCell[2]={1, 3};

struct pallet {
  int row;
  int column;
}pallets[]{
  {3, 3}, //pallet N°1
  {3, 3}, //pallet N°2
  {3, 3}, //pallet N°3
  {3, 3}, //pallet N°4
  {3, 3}, //pallet N°5
  {3, 3}, //pallet N°6
  {3, 3}, //pallet N°7
  {3, 3}, //pallet N°8
  {3, 3}, //pallet N°9
};

Warehouse warehouse;
struct menu menuMain;

void setup() {
  Serial.begin(9600);
  movement.begin();
  numberPad.begin();
  warehouse.begin();
  Serial.println("START");
  warehouse.downloadEEPROM();
  if(EEPROM[9] == 0 || EEPROM[9] == 1)
    oldModality = EEPROM[9];
  else
    oldModality = 0;
    
  menuMain = warehouse.startMenu(oldModality);
  if(menuMain.reset){
    for(int i = 0; i < 9; i++){
      pallets[i].column = 3;
      pallets[i].row = 3;
    }
  }
  delay(200);

  warehouse.print(PRINT_START);
  warehouse.moveToStart();
}

void loop() {
restart:
    if(menuMain.modality == MANUAL){
      destinationCell[0] = warehouse.request(PRINT_ROW);
      if(destinationCell[0] == MENU){
        actualCell[0] = 0;
        actualCell[1] = 3;
        menuMain = warehouse.startMenu(menuMain.modality);
        if(menuMain.reset){
          for(int i = 0; i < 9; i++){
            pallets[i].column = 3;
            pallets[i].row = 3;
           }
        }
        goto restart;
      }
      delay(200);
      destinationCell[1] = warehouse.request(PRINT_COLUMN);
      if(destinationCell[1] == MENU){
        actualCell[0] = 0;
        actualCell[1] = 3;
        menuMain = warehouse.startMenu(menuMain.modality);
        if(menuMain.reset){
          for(int i = 0; i < 9; i++){
            pallets[i].column = 3;
            pallets[i].row = 3;
           }
        }
        goto restart;
      }
      delay(200);
      if(warehouse.isCellEmpty(destinationCell)){
        warehouse.storePallet(actualCell, destinationCell, 1, menuMain.simulation);
        actualCell[0] = 0;
        actualCell[1] = 3;
        warehouse.moveToStart();
      }
      
      else{
        warehouse.getPallet(actualCell, destinationCell, unloadCell, menuMain.simulation);
        actualCell[0] = 1;
        actualCell[1] = 3;
      }
    }
    
    else if(menuMain.modality == AUTOMATIC){
      warehouse.draw();
      num = warehouse.request(PRINT_PALLET);
      delay(200);
      if(num == MENU){
        actualCell[0] = 0;
        actualCell[1] = 3;
        menuMain = warehouse.startMenu(menuMain.modality);
        if(menuMain.reset){
          for(int i = 0; i < 9; i++){
            pallets[i].column = 3;
            pallets[i].row = 3;
           }
        }
        goto restart;
      }
      
      if(pallets[num-1].row == 3 || pallets[num-1].column == 3){
        pallets[num-1].row = warehouse.getFirstCellFreeRow();
        pallets[num-1].column = warehouse.getFirstCellFreeColumn();
        destinationCell[0] = pallets[num-1].row;
        destinationCell[1] = pallets[num-1].column;
        warehouse.storePallet(actualCell, destinationCell, num, menuMain.simulation);
        actualCell[0] = 0;
        actualCell[1] = 3;
        if(!menuMain.simulation) warehouse.moveToStart();
        warehouse.draw();
      }
      else{
        destinationCell[0] = pallets[num-1].row;
        destinationCell[1] = pallets[num-1].column;
        warehouse.getPallet(actualCell, destinationCell, unloadCell, menuMain.simulation);
        pallets[num-1].row = 3;
        pallets[num-1].column = 3;
        actualCell[0] = 1;
        actualCell[1] = 3;
        warehouse.print(PRINT_OPTIMIZATION);
        byte fromCell[2] = {warehouse.getLastCellFullRow(), warehouse.getLastCellFullColumn()};
        warehouse.getPallet(actualCell, fromCell, destinationCell, menuMain.simulation);
        byte num = warehouse.numPalletInCell(destinationCell);
        pallets[num-1].row = destinationCell[0];
        pallets[num-1].column = destinationCell[1];
        warehouse.draw();
      }
      
    }
    
    else if(menuMain.modality == DEBUG){
      warehouse.print(PRINT_DEBUG);
      byte button = numberPad.readKey();
      delay(200);
      int dist = 300;
      switch (button){
        case(UP):
          movement.move(UP, dist);
          break;

        case(DOWN):
          movement.move(DOWN, dist);
          break;
          
        case(RIGHT):
          movement.move(RIGHT, dist);
          break;
          
        case(LEFT):
          movement.move(LEFT, dist);
          break;
          
        case(ACTUATOR_FOWARD):
          movement.actuator(1, 0);
          break;
          
        case(ACTUATOR_BACKWARD):
          movement.actuator(0, 1);
          break;

        case(MENU):
          delay(200);
          actualCell[0] = 0;
          actualCell[1] = 3;
          menuMain = warehouse.startMenu(menuMain.modality);
          if(menuMain.reset){
            for(int i = 0; i < 9; i++){
              pallets[i].column = 3;
              pallets[i].row = 3;
            }
          }
          goto restart;
          
        default:
          movement.actuator(0, 0);
          break;
      }
      delay(100);
    }
    
    else if(menuMain.modality == MEASURES){
      warehouse.print(PRINT_MEASURES);
      byte button = numberPad.readKey();
      switch (button){
        case(UP):
          if(actualCell[0] != 2) destinationCell[0] = actualCell[0]+1;
          destinationCell[1] = actualCell[1];
          break;

        case(DOWN):
          if(actualCell[0] != 0) destinationCell[0] = actualCell[0]-1;
          destinationCell[1] = actualCell[1];
          break;
          
        case(RIGHT):
          if(actualCell[1] != 0) destinationCell[1] = actualCell[1]-1;
          destinationCell[0] = actualCell[0];
          break;
          
        case(LEFT):
          if(actualCell[1] != 3) destinationCell[1] = actualCell[1]+1;
          destinationCell[0] = actualCell[0];
          break;
          
        case(ACTUATOR_FOWARD):
          movement.actuator(1, 0);
          delay(TIME_ACTUATOR);
          movement.actuator(0, 0);
          break;
          
        case(ACTUATOR_BACKWARD):
          movement.actuator(0, 1);
          delay(TIME_ACTUATOR);
          movement.actuator(0, 0);
          break;
          
        case(PALLET_UP_DOWN):
          movement.move(UP, PALLET_VERTICAL_DISTANCE);
          delay(1000);
          movement.move(DOWN, PALLET_VERTICAL_DISTANCE);
          break;

        case(MENU):
          delay(200);
          actualCell[0] = 0;
          actualCell[1] = 3;
          menuMain = warehouse.startMenu(menuMain.modality);
          if(menuMain.reset){
            for(int i = 0; i < 9; i++){
              pallets[i].column = 3;
              pallets[i].row = 3;
            }
          }
          goto restart;
          
        default:
          movement.actuator(0, 0);
          break;
      }
      if(button == UP || button == DOWN || button == LEFT || button == RIGHT){
        movement.moveBetweenCells(actualCell, destinationCell);
        actualCell[0] = destinationCell[0];
        actualCell[1] = destinationCell[1];
      }
      delay(100);
      
    }
}
