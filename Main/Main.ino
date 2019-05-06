
#include <Arduino.h>
#include <EEPROM.h>
#include "StepperMotor.h"
#include "Warehouse.h"
byte array[4]={H_BRIDGE1_PH1_PIN, H_BRIDGE1_PH2_PIN, H_BRIDGE1_PH3_PIN, H_BRIDGE1_PH4_PIN};
StepperMotor motorX = StepperMotor(array);

bool oldModality, modality;
byte reset;

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
  warehouse.begin();
  motorX.begin();
  warehouse.downloadEEPROM();
  oldModality = EEPROM[9];
  warehouse.draw();
  /*modality = warehouse.requestModality();                                         //stampare sul display "scegliere modalità: 0.manuale 1.automatica", aspettare bottone premuto, return modalità
  if(modality!=oldModality) warehouse.conversionOfMatrix(modality, oldModality);  //se mod=man e oldMod=auto ->matrix trasformata in 1 e 0, se mod=auto e oldMod=man -> matrix trasformata in da 0 a 9
  reset = warehouse.requestReset();                                               //stampare sul display "scegliere rest: 0.no reset 1.reset(tutto=0) 2.inizz.(spostamento per il magazzino)", aspettare bbottone e return
  if(reset==1) warehouse.resetMatrix();                                           //portare a 0 tutte le celle di matrix
  else if(reset==INITIALIZATION) warehouse.initializeMatrix();  */                  //spostare il braccio per tutto il maggazzino e rilevare i pallet
}

void loop() {
}
