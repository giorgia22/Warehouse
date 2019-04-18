#include "numberPad.h"
NumberPad tastierino(40, 42, 44, 46, 48, 50, 52);
  
void setup() {
  Serial.begin(9600);
  tastierino.begin();
}

void loop() {
  Serial.println(tastierino.readKey());
}
