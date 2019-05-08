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
  int row=0;
  for(int y=1; y<6; y=y+2){
    int column=0;
    for(int x=1; x<8; x=x+3){
      GLCD.CursorTo(x, y);
      GLCD.print(matrix[row][column]);
      column++;
    }
  row++;
  }
}

void Display::printModality(){
  GLCD.CursorTo(9,0);
  GLCD.print("Inserire");
  GLCD.CursorTo(9,1);
  GLCD.print("modalita':");
  GLCD.CursorTo(9,3);
  GLCD.print("0.manuale");
  GLCD.CursorTo(9,4);
  GLCD.print("1.automatica");
}
