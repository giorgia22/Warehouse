#ifndef NUMBER_PAD_H
#define NUMBER_PAD_H

#include <Arduino.h>

class NumberPad{
public:
    NumberPad(unsigned int A, unsigned int B, unsigned int C, unsigned int D, unsigned int E, unsigned int F, unsigned int G);
    void begin();
    unsigned int readKey();
    void write(bool nA, bool nB, bool nC);
    int read();

private:
    unsigned int A, B, C, D, E, F, G;
    unsigned int numbers[4][3] = {{11, 0, 10}, {9, 8, 7}, {6, 5, 4}, {3, 2, 1}}; //10=<-     11=AVANT
};

#endif
