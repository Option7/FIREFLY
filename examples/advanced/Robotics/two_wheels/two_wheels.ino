#include <FIREFLY.h>

MOTOR motorA(9, 8); //IN1, IN2
MOTOR motorB(10, 11); //IN3, IN4
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
motorA.forward();
motorB.forward();

}
