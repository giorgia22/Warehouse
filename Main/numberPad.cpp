#include "NumberPad.h"
NumberPad::NumberPad(byte pins[7]){
    this->pins[0] = pins[0];
    this->pins[1] = pins[1];
    this->pins[2] = pins[2];
    this->pins[3] = pins[3];
    this->pins[4] = pins[4];
    this->pins[5] = pins[5];
    this->pins[6] = pins[6];
}

void NumberPad::begin(){
    for(int i=0; i<3; i++) pinMode( pins[i], OUTPUT);
    for(int i=3; i<7; i++) pinMode( pins[i], INPUT_PULLUP);
}

void NumberPad::write(bool outputValues[3]){
    for(int i=0; i<3; i++)
      digitalWrite(pins[i], outputValues[i]);
}

int NumberPad::read(){
    for(int i=3; i<7; i++){
      if(!digitalRead(pins[i]))
        return (i-3);
    }
    
    return 4;
}

int NumberPad::readKey(){
    bool arrayColumn[3] = {true, true, true};
    int row = 4, column = 4;
    while(row == 4){
      for(int j = 0; j < 3 && row == 4; j++){
        
        for(int i = 0; i < 3; i++) arrayColumn[i]  = true;
        arrayColumn[j] = false;
        write(arrayColumn);
        
        row = read();
        if(row != 4) column = j;
      }
    }
    return numbers[row][column];
}
