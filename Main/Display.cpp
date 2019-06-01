#include "Display.h"

Display:: Display() {}

void Display::begin(){
  GLCD.Init();
  GLCD.SelectFont(System5x7);
}

void Display::drawWarehouse(int lato, int matrix[3][3]){
  GLCD.ClearScreen();
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      GLCD.DrawRect(lato*j+1, lato*i+2, lato, lato);
    }
  }
  int row = 0;
  for(int y = 1; y < 6; y = y + 2){
    int column = 0;
    for(int x = 1; x < 8; x = x + 3){
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
      GLCD.CursorTo(0, 0);
      GLCD.print("Inserire modalita'");
      GLCD.CursorTo(0, 1);
      GLCD.print("di funzionamento:");
      GLCD.CursorTo(0, 3);
      GLCD.print("0.manuale");
      GLCD.CursorTo(0, 4);
      GLCD.print("1.automatica");
      GLCD.CursorTo(0, 5);
      GLCD.print("2.posizionamento");
      break;
      
    case PRINT_RESET:
      GLCD.CursorTo(9, 0);
      GLCD.print("Inserire");
      GLCD.CursorTo(9, 1);
      GLCD.print("modalita' di");
      GLCD.CursorTo(9, 2);
      GLCD.print("resettaggio:");
      GLCD.CursorTo(9, 4);
      GLCD.print("0.no reset");
      GLCD.CursorTo(9, 5);
      GLCD.print("1.reset");
      GLCD.CursorTo(9, 6);
      GLCD.print("2.inizializ=");
      GLCD.CursorTo(9, 7);
      GLCD.print("zazione");
      break;
      
    case PRINT_ROW:
      GLCD.CursorTo(9, 0);
      GLCD.print("Inserire");
      GLCD.CursorTo(9, 1);
      GLCD.print("riga");
      GLCD.CursorTo(9, 6);
      GLCD.print("<-START MENU'");
      break;
      
    case PRINT_COLUMN:
      GLCD.CursorTo(9, 0);
      GLCD.print("Inserire");
      GLCD.CursorTo(9, 1);
      GLCD.print("colonna");
      GLCD.CursorTo(9, 6);
      GLCD.print("<-START MENU'");
      break;

    case PRINT_PALLET:
      GLCD.CursorTo(9, 0);
      GLCD.print("Inserire ");
      GLCD.CursorTo(9, 1);
      GLCD.print("n pallet:");
      GLCD.CursorTo(9, 6);
      GLCD.print("<-START MENU'");
      break;

    case(PRINT_DEPOSITO):
      GLCD.CursorTo(0, 0);
      GLCD.print("Deposizione del");
      GLCD.CursorTo(0, 1);
      GLCD.print("pallet nel magazzino.");
      GLCD.CursorTo(0, 3);
      GLCD.print("Attendere...");
      break;
      
    case(PRINT_PRELIEVO):
      GLCD.CursorTo(0, 0);
      GLCD.print("Prelevamento del");
      GLCD.CursorTo(0, 1);
      GLCD.print("pallet dal magazzino.");
      GLCD.CursorTo(0, 3);
      GLCD.print("Attendere...");
      break;

    case(PRINT_DEBUG):
      GLCD.CursorTo(0, 0);
      GLCD.print("0.UP");
      GLCD.CursorTo(0, 1);
      GLCD.print("1.DOWN");
      GLCD.CursorTo(0, 2);
      GLCD.print("2.LEFT");
      GLCD.CursorTo(0, 3);
      GLCD.print("3.RIGHT");
      GLCD.CursorTo(0, 4);
      GLCD.print("5.ACTUATOR FOWARD");
      GLCD.CursorTo(0, 5);
      GLCD.print("6.ACTUATOR BACKWARD");
      GLCD.CursorTo(5, 6);
      GLCD.print("<-START MENU'");
      break;

    case(PRINT_BEGIN):
      GLCD.CursorTo(0, 0);
      GLCD.print("Avviamento del");
      GLCD.CursorTo(0, 1);
      GLCD.print("magazzino...");
      break;

    case(PRINT_START):
      GLCD.CursorTo(0, 0);
      GLCD.print("Posizionamento cella");
      GLCD.CursorTo(0, 1);
      GLCD.print("iniziale");
      break;
      
    default:
      break;
  }
}

void Display::clear(){
  GLCD.ClearScreen();
}
