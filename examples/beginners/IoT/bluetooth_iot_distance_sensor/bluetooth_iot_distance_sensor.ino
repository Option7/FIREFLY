#include <FIREFLY.h>

BLUETOOTH  bluetooth;
ULTRASONIC ultrasonic; 

void setup() {
  // put your setup code here, to run once:
}
 
void loop() {
  // put your main code here, to run repeatedly:

  int distance = ultrasonic.distance();

  bluetooth.sendNumber(distance);

  delay(2000);
   
    
  
}
