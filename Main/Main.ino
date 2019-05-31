#include <Arduino.h>
#include <EEPROM.h>
#include "Warehouse.h"
#include "Moviment.h"
#include "NumberPad.h"

Moviment moviment;
byte numberPadPins[7]={NUMBER_PAD_A_PIN, NUMBER_PAD_B_PIN, NUMBER_PAD_C_PIN, NUMBER_PAD_D_PIN, NUMBER_PAD_E_PIN, NUMBER_PAD_F_PIN, NUMBER_PAD_G_PIN};
NumberPad numberPad = NumberPad(numberPadPins);

byte oldModality, modality;
byte reset;
byte num;
byte actualCell[2]={0, 3}, destinationCell[2];



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

void setup() {
  Serial.begin(9600);
  moviment.begin();
  numberPad.begin();
  warehouse.begin();
  
  warehouse.downloadEEPROM();
  if(EEPROM[9] == 0 || EEPROM[9] == 1)
    oldModality = EEPROM[9];
  else
    oldModality = 0;
     
  modality = warehouse.startMenu();                                                                            //stampare sul display "scegliere modalità: 0.manuale 1.automatica", aspettare bottone premuto, return modalità
  if(modality != oldModality && (modality == 0 || modality == 1)) warehouse.conversionOfMatrix(modality, oldModality);     //se mod=man e oldMod=auto ->matrix trasformata in 1 e 0, se mod=auto e oldMod=man -> matrix trasformata in da 0 a 9
  delay(200);                                                         //spostare il braccio per tutto il maggazzino e rilevare i pallet
  
  warehouse.print(PRINT_START);
  warehouse.moveToStart();
}

void loop() {
restart:
    if(modality == MANUAL){
      destinationCell[0] = warehouse.request(PRINT_ROW);
      if(destinationCell[0] == MENU){
        actualCell[0] = 0;
        actualCell[1] = 3;
        modality = warehouse.startMenu();
        goto restart;
      }
      delay(200);
      destinationCell[1] = warehouse.request(PRINT_COLUMN);
      if(destinationCell[1] == MENU){
        actualCell[0] = 0;
        actualCell[1] = 3;
        modality = warehouse.startMenu();
        goto restart;
      }
      
      if(warehouse.isCellEmpty(destinationCell)){
        warehouse.storePallet(actualCell, destinationCell, 1);
        actualCell[0] = 0;
        actualCell[1] = 3;
        warehouse.moveToStart();
      }
      
      else{
        warehouse.getPallet(actualCell, destinationCell);
        actualCell[0] = 1;
        actualCell[1] = 3;
      }
    }
    
    else if(modality == AUTOMATIC){
      warehouse.draw();
      num = warehouse.request(PRINT_PALLET);
      if(num == MENU){
        actualCell[0] = 0;
        actualCell[1] = 3;
        modality = warehouse.startMenu();
        goto restart;
      }
      
      if(pallets[num-1].row == 3 || pallets[num-1].column == 3){
        pallets[num-1].row = warehouse.getRow();
        pallets[num-1].column = warehouse.getColumn();
        destinationCell[0] = pallets[num-1].row;
        destinationCell[1] = pallets[num-1].column;
        warehouse.storePallet(actualCell, destinationCell, num);
        actualCell[0] = 0;
        actualCell[1] = 3;
        warehouse.draw();
      }
      else{
        destinationCell[0] = pallets[num-1].row;
        destinationCell[1] = pallets[num-1].column;
        warehouse.getPallet(actualCell, destinationCell);
        pallets[num-1].row = 3;
        pallets[num-1].column = 3;
        actualCell[0] = 1;
        actualCell[1] = 3;
        warehouse.draw();
      }
      
    }
    
    else if(modality == DEBUG){
      warehouse.print(PRINT_DEBUG);
      byte button = numberPad.readKey();
      int dist=300;
      switch (button){
        case(UP):
          moviment.move(UP, dist);
          break;

        case(DOWN):
          moviment.move(DOWN, dist);
          break;
          
        case(RIGHT):
          moviment.move(RIGHT, dist);
          break;
          
        case(LEFT):
          moviment.move(LEFT, dist);
          break;
          
        case(ACTUATOR_FOWARD):
          moviment.actuator(1, 0);
          break;
          
        case(ACTUATOR_BACKWARD):
          moviment.actuator(0, 1);
          break;

        case(MENU):
          delay(200);
          actualCell[0] = 0;
          actualCell[1] = 3;
          modality = warehouse.startMenu();
          goto restart;
          
        default:
          moviment.actuator(0, 0);
          break;
      }
      delay(100);
    }
    
    else if(modality == MEASURES){
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
          moviment.actuator(1, 0);
          delay(TIME_ACTUATOR);
          moviment.actuator(0, 0);
          break;
          
        case(ACTUATOR_BACKWARD):
          moviment.actuator(0, 1);
          delay(TIME_ACTUATOR);
          moviment.actuator(0, 0);
          break;
          
        case(PALLET_UP_DOWN):
          moviment.move(UP, PALLET_VERTICAL_DISTANCE);
          delay(1000);
          moviment.move(DOWN, PALLET_VERTICAL_DISTANCE);
          break;

        case(MENU):
          delay(200);
          actualCell[0] = 0;
          actualCell[1] = 3;
          modality = warehouse.startMenu();
          goto restart;
          
        default:
          moviment.actuator(0, 0);
          break;
      }
      if(button == UP || button == DOWN || button == LEFT || button == RIGHT){
        moviment.moveBetweenCells(actualCell, destinationCell);
        actualCell[0] = destinationCell[0];
        actualCell[1] = destinationCell[1];
      }
      delay(100);
      
    }
}
