#include "Display.h"

Display::Display() {}

void Display::begin() {
  GLCD.Init();
  GLCD.SelectFont(System5x7);
}

void Display::drawWarehouse(int lato, int matrix[3][3]){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      GLCD.DrawRect(lato*j+1, lato*i+2, lato, lato);
    }
  }

  for(int y=1; y<6; y=y+2){
    for(int x=1; x<8; x=x+3){
      GLCD.CursorTo(x, y);
      GLCD.print("1");
    }
  }
}
