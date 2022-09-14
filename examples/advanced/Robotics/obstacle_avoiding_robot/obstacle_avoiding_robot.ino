#include <FIREFLY.h>

ULTRASONIC ultraSonic(6,7);
MOTOR motorA(9, 8); //IN1, IN2
MOTOR motorB(10, 11); //IN3, IN4
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:

if (ultraSonic.getDistance() < 30){
motorA.reverse();
motorB.forward();
}

if (ultraSonic.getDistance() > 30){
motorA.forward();
motorB.forward();
} 
Serial.println(ultraSonic.getDistance());
}
