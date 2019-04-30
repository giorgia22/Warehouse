#include "Moviment.h"

Moviment::Moviment(){
}

void Moviment::begin(){
  motorX.begin();
  motorY.begin();
}

void Moviment::move(bool orientation, float degrees){
  motorX.move(orientation, degrees);
}
