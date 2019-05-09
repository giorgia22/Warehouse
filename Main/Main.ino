#include <Arduino.h>
#include <EEPROM.h>
#include "StepperMotor.h"
#include "Warehouse.h"

byte oldModality, modality;
byte reset;

byte actualCell[2]={0, 3}, destinationCell[2];


Warehouse warehouse;

void setup() {
  warehouse.begin();
  warehouse.downloadEEPROM();
  if(EEPROM[9]==0 || EEPROM[9]==1)
    oldModality = EEPROM[9];
  else
    oldModality=0;
  warehouse.draw();
  modality = warehouse.request(PRINT_MODALITY);                                            //stampare sul display "scegliere modalità: 0.manuale 1.automatica", aspettare bottone premuto, return modalità
  if(modality!=oldModality) warehouse.conversionOfMatrix(modality, oldModality);     //se mod=man e oldMod=auto ->matrix trasformata in 1 e 0, se mod=auto e oldMod=man -> matrix trasformata in da 0 a 9
  warehouse.draw();
  reset = warehouse.request(PRINT_RESET);                                                  //stampare sul display "scegliere reset: 0.no reset 1.reset(tutto=0) 2.inizz.(spostamento per il magazzino)", aspettare bottone e return
  if(reset==1) warehouse.resetMatrix();                                              //portare a 0 tutte le celle di matrix
  else if(reset==INITIALIZATION) warehouse.initializeMatrix();                       //spostare il braccio per tutto il maggazzino e rilevare i pallet
}

void loop() {
    if(modality==MANUAL){
      destinationCell[0]=warehouse.request(PRINT_ROW);
      destinationCell[1]=warehouse.request(PRINT_COLUMN);
      if(warehouse.isCellEmpty(destinationCell)){
        warehouse.storePallet(actualCell, destinationCell, 1);
        actualCell[0]=0;
        actualCell[1]=3;
        warehouse.draw();
      }
      else{
        warehouse.getPallet(actualCell, destinationCell);
        actualCell[0]=1;
        actualCell[1]=3;
        warehouse.draw();
      }
    }
}
