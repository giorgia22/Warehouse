#ifndef NUMBER_PAD_H
#define NUMBER_PAD_H

#include <Arduino.h>

class NumberPad{
public:
    NumberPad(byte pins[7]);
    void begin();
    int readKey();

private:
    byte pins[7];
    int numbers[4][3] = {{11, 0, 10}, {9, 8, 7}, {6, 5, 4}, {3, 2, 1}}; //10=<-     11=AVANT
    
    void write(bool outputValues[3]);
    int read();
};

#endif
