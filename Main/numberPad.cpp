#include "NumberPad.h"

NumberPad::NumberPad(byte pins[7]){
    for(int i = 0; i < 7; i++)
      this->pins[i] = pins[i];
}

void NumberPad::begin(){
    for(int i = 0; i < 3; i++) pinMode(pins[i], OUTPUT);
    for(int i = 3; i < 7; i++) pinMode(pins[i], INPUT_PULLUP);
}

void NumberPad::write(bool outputValues[3]){
    for(int i = 0; i < 3; i++)
      digitalWrite(pins[i], outputValues[i]);
}

int NumberPad::read(){
    for(int i = 3; i < 7; i++){
      if(!digitalRead(pins[i]))
        return (i-3);
    }
    return 4;
}

int NumberPad::readKey(){
    bool arrayColumn[3];
    int row = 4, column = 3;
      for(int j = 0; j < 3 && row == 4; j++){
        for(int i = 0; i < 3; i++) arrayColumn[i]  = true;
        arrayColumn[j] = false;
        write(arrayColumn);
        
        row = read();
        if(row != 4) column = j;
      }
    if (row == 4) return 12;
    else return numbers[row][column];
}
