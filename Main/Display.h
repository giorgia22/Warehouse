#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <openGLCD.h>
#include "definitions.h"

class Display {
public:
    Display ();
    void begin ();
    void drawWarehouse(int lato, int matrix[3][3]);
    void print(byte variable);
    void clear();

private:

};

#endif
