#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <openGLCD.h>

class Display {
public:
    Display ();
    void begin ();
    void drawWarehouse(int lato, int matrix[3][3]);
    

private:


};

#endif
