#include <FIREFLY.h>

BLUETOOTH bluetooth;
RGB       rgb; 

void setup() {
  // put your setup code here, to run once:
}
 
void loop() {
  // put your main code here, to run repeatedly:


  if (bluetooth.receiveCommand() == 'R'){ //Forward
   
    rgb.redOn();
    rgb.greenOff();
    rgb.blueOff();
  }

  if (bluetooth.receiveCommand() == 'G'){ //Forward
   
    rgb.redOff();
    rgb.greenOn();
    rgb.blueOff();
  }

  if (bluetooth.receiveCommand() == 'B'){ //Forward
   
    rgb.redOff();
    rgb.greenOff();
    rgb.blueOn();
  }

  
}
