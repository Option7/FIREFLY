#include <FIREFLY.h>

BLUETOOTH bluetooth;
MOTOR motor; 

void setup() {
  // put your setup code here, to run once:
}
 
void loop() {
  // put your main code here, to run repeatedly:


  if (bluetooth.receiveCommand() == '1'){ //Forward
   
    motor.leftForward();
    motor.rightForward();
    delay(1000);
    motor.leftStop();
    motor.rightStop();
  }

  if (bluetooth.receiveCommand() == '2'){ //Reverse
    
    motor.leftReverse();
    motor.rightReverse();
    delay(1000);
    motor.leftStop();
    motor.rightStop();
  }

  if (bluetooth.receiveCommand() == '3'){ //Right turn
   
    motor.leftForward();
    motor.rightReverse();
    delay(1000);
    motor.leftStop();
    motor.rightStop();
  }

  if (bluetooth.receiveCommand() == '4'){ //Left turn
    
    motor.leftReverse();
    motor.rightForward();
    delay(1000);
    motor.leftStop();
    motor.rightStop();
  }

  if (bluetooth.receiveCommand() == '5'){ //Stop
    
    motor.leftStop();
    motor.rightStop();
  }

}
