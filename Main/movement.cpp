#include "movement.h"

movement::movement(){
}

void movement::begin(){
  motorX.begin();
  motorY.begin();
  pinMode(ACTUATOR_POS_PIN, OUTPUT);
  pinMode(ACTUATOR_NEG_PIN, OUTPUT);
  pinMode(FC1_PIN, INPUT_PULLUP);
  pinMode(FC2_PIN, INPUT_PULLUP);
  pinMode(FC3_PIN, INPUT_PULLUP);
  pinMode(FC4_PIN, INPUT_PULLUP);
}

void movement::move(byte direction, float degrees){
  byte FC;
  switch(direction){
    case (UP):
        FC = FC4_PIN;
        break;
    case (DOWN):
        FC = FC3_PIN;
        break;
    case (LEFT):
        FC = FC1_PIN;
        break;
    case (RIGHT):
        FC = FC2_PIN;
        break;
  }
  if(direction == LEFT || direction == RIGHT) motorX.move(direction%2, degrees, FC);
  else if(direction == UP || direction == DOWN) motorY.move(direction%2, degrees, FC);
}

void movement::moveBetweenCells(byte fromCell[2], byte toCell[2]){
  byte row = 0;
  byte column = 1;
  if(fromCell[column] < toCell[column])   move(LEFT, distance(false, fromCell[column], toCell[column]));
  if(fromCell[column] > toCell[column])   move(RIGHT, distance(false, fromCell[column], toCell[column]));
  if(fromCell[row] < toCell[row])         move(UP, distance(true, fromCell[row], toCell[row]));
  if(fromCell[row] > toCell[row])         move(DOWN, distance(true, fromCell[row], toCell[row]));
}

float movement::distance(bool direction, byte a, byte b){
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


void movement::actuator(bool pos, bool neg){
  digitalWrite(ACTUATOR_POS_PIN, pos);
  digitalWrite(ACTUATOR_NEG_PIN, neg);
}

void movement::pickPallet(bool direction){
  actuator(true, false);
  delay(TIME_ACTUATOR);
  actuator(false, false);
  move(direction, PALLET_VERTICAL_DISTANCE);
  actuator(false, true);
  delay(TIME_ACTUATOR);
  actuator(false, false);
}

void movement::moveToStart(){
  while(analogRead(FC3_PIN) > 800) move(DOWN, 16.2);
  while(analogRead(FC1_PIN) > 800) move(LEFT, 16.2);
}
