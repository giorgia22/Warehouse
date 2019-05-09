#include "Display.h"
#include "definitions.h"

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
      GLCD.print(matrix[2-row][2-column]);
      column++;
    }
  row++;
  }
}

void Display::print(byte variable){
  switch (variable){
    case PRINT_MODALITY:
      GLCD.CursorTo(0,0);
      GLCD.print("Inserire modalita'");
      GLCD.CursorTo(0,1);
      GLCD.print("di funzionamento:");
      GLCD.CursorTo(0,3);
      GLCD.print("0.manuale");
      GLCD.CursorTo(0,4);
      GLCD.print("1.automatica");
      break;
      
    case PRINT_RESET:
      GLCD.CursorTo(9,0);
      GLCD.print("Inserire");
      GLCD.CursorTo(9,1);
      GLCD.print("modalita' di");
      GLCD.CursorTo(9,2);
      GLCD.print("resettaggio:");
      GLCD.CursorTo(9,4);
      GLCD.print("0.no reset");
      GLCD.CursorTo(9,5);
      GLCD.print("1.reset");
      GLCD.CursorTo(9,6);
      GLCD.print("2.inizializ=");
      GLCD.CursorTo(9,7);
      GLCD.print("zazione");
      break;
      
    case PRINT_ROW:
      GLCD.CursorTo(0,0);
      GLCD.print("Inserire riga:");
      break;
      
    case PRINT_COLUMN:
      GLCD.CursorTo(0,0);
      GLCD.print("Inserire colonna:");
      break;
      
    default:
      break;
  }
}

void Display::clear(){
  GLCD.ClearScreen();
}
