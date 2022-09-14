#include <FIREFLY.h>


MOTOR   motorA(9, 8);     //IN1, IN2, 
MOTOR   motorB(10, 11);   //IN3, IN4, 
SPEED   enAspeed(12);     //ENA
SPEED   enBspeed(13);     //ENB

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}
 
void loop() {
  // put your main code here, to run repeatedly:

enAspeed.setSpeed(50);
motorA.reverse();

enBspeed.setSpeed(50);
motorA.reverse();
}
