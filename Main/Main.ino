
#include <Arduino.h>
#include <openGLCD.h>
#include "StepperMotor.h"
#include "NumberPad.h"

StepperMotor motorX(8,9,10,11);

void setup() {
  motorX.begin();
  GLCD.Init();
  GLCD.SelectFont(System5x7);

 // Draw warehouse
/*  int lato=17;
  
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      GLCD.DrawRect(lato*j+1, lato*i+2, lato, lato);
    }
  }

 // Fill warehouse with numbers
  for(int y=1; y<6; y=y+2){
    for(int x=1; x<8; x=x+3){
      GLCD.CursorTo(x, y);
      GLCD.print("1");
    }
  }*/
}

void loop() {
  motorX.move(true, 180);
  delay(200);
  motorX.move(false, 180);
  delay(200);
}
