#include "Moviment.h"

Moviment::Moviment(){
}

void Moviment::begin(){
  motorX.begin();
  motorY.begin();
  pinMode(ACTUATOR_POS_PIN, OUTPUT);
  pinMode(ACTUATOR_NEG_PIN, OUTPUT);
}

void Moviment::move(byte direction, float degrees){
  if(direction == LEFT || direction == RIGHT) motorX.move(direction%2, degrees);
  else if(direction == UP || direction == DOWN) motorY.move(direction%2, degrees);
}

void Moviment::moveBetweenCells(byte fromCell[2], byte toCell[2]){
  byte row = 0;
  byte column = 1;
  if(fromCell[column] < toCell[column])   move(LEFT, distance(false, fromCell[column], toCell[column]));
  if(fromCell[column] > toCell[column])   move(RIGHT, distance(false, fromCell[column], toCell[column]));
  if(fromCell[row] < toCell[row])         move(UP, distance(true, fromCell[row], toCell[row]));
  if(fromCell[row] > toCell[row])         move(DOWN, distance(true, fromCell[row], toCell[row]));
}

float Moviment::distance(bool direction, byte a, byte b){
  int distance = 0;
  byte greater = max(a, b);
  byte smaller = min(a, b);
  while(smaller < greater){
    if(direction)
      distance += verticalDistances[smaller];
    else
      distance += horizontalDistances[smaller];
    smaller++;
  }
  return distance;
}


void Moviment::actuator(bool pos, bool neg){
  digitalWrite(ACTUATOR_POS_PIN, pos);
  digitalWrite(ACTUATOR_NEG_PIN, neg);
}

void Moviment::pickPallet(bool direction){
  actuator(true, false);
  delay(TIME_ACTUATOR);
  actuator(false, false);
  move(direction, PALLET_VERTICAL_DISTANCE);
  actuator(false, true);
  delay(TIME_ACTUATOR);
  actuator(false, false);
}

void Moviment::moveToStart(){
  while(analogRead(FC3_PIN) > 800) move(DOWN, 16.2);
  while(analogRead(FC1_PIN) > 800) move(LEFT, 16.2);
}
