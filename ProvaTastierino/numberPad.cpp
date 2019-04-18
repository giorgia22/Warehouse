#include "numberPad.h"
NumberPad::NumberPad(unsigned int A, unsigned int B, unsigned int C, unsigned int D, unsigned int E, unsigned int F, unsigned int G){
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    this->E = E;
    this->F = F;
    this->G = G;
}

void NumberPad::begin(){
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, INPUT_PULLUP);
    pinMode(E, INPUT_PULLUP);
    pinMode(F, INPUT_PULLUP);
    pinMode(G, INPUT_PULLUP);
}

void NumberPad::write(bool nA, bool nB, bool nC){
    digitalWrite(A, nA);
    digitalWrite(B, nB);
    digitalWrite(C, nC);
}

int NumberPad::read(){
    if(!digitalRead(D))
        return 0;
    else if(!digitalRead(E))
        return 1;
    else if (!digitalRead(F))
        return 2;
    else if (!digitalRead(G))
        return 3;
    else
        return 4;
}

unsigned int NumberPad::readKey(){
    bool arrayColumn[3];
    unsigned int row = 4, column;
    while(row == 4){
      for(column=0; column < 3; column++){
        for(int i=0; i < 3; i++) arrayColumn[i]  = true;
        arrayColumn[column] = false;
        write(arrayColumn[0], arrayColumn[1], arrayColumn[2]);
        row = read();
      }
    }
    return numbers[row][column];
}
