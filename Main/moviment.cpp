#include "Moviment.h"

Moviment::Moviment(){
}

void Moviment::begin(){
  motorX.begin();
  motorY.begin();
  pinMode(ACTUATOR_POS_PIN, OUTPUT);
  pinMode(ACTUATOR_NEG_PIN, OUTPUT);
}

void Moviment::move(bool orientation, float degrees){
  motorX.move(orientation, degrees);
}

void Moviment::moveToCell(int row, int column){
  while(digitalRead(FC1_PIN)) motorX.move(LEFT, 1.8);
  while(digitalRead(FC3_PIN)) motorY.move(DOWN, 1.8);

  for(int i=0; i<=row; i++) motorX.moveCm(RIGHT, DISTANCE_BETWEEN_CELLS_X);
  for(int i=2; i>column; i--) motorY.moveCm(UP, DISTANCE_BETWEEN_CELLS_Y);
}
