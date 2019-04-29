/*
 *  openGLCD Library - Hello World
 * 
 * This sketch prints "Hello World!" to the LCD
 * and shows the time in seconds since Arduino board was reset.
 * 
 *  2013-06-15 bperrybap   - updates for openGLCD
 *  2011-09-14 Bill Perry  - original creation
 *  	bperrybap@opensource.billsworld.billandterrie.com
 */

// include the library header
// no font headers have to be included
#include <openGLCD.h>

void setup()
{
  // Initialize the GLCD 
  GLCD.Init();

 // Select the font for the default text area
  GLCD.SelectFont(System5x7);
 // Draw warehouse structure
  int lato=17;
  
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
  }
  
}

void loop()
{
}
