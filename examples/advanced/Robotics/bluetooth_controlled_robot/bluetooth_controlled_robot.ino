#include <FIREFLY.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth  (10, 11);   //RX, TX
MOTOR          motorA     (7, 6);   //IN1, IN2
MOTOR          motorB     (8, 9); //IN3, IN4
void setup() {
  // put your setup code here, to run once:

bluetooth.begin(9600);  //Initialise BLUETOOTH
}
 
void loop() {
  // put your main code here, to run repeatedly:


int incoming_commands = bluetooth.read(); //snippet to capture bluetooth commands in INTEGERS
while (bluetooth.available()){}               //if command is available over bluetooth

//command for moving robot FORWARD
if (incoming_commands == '1'){ //if command over bluetooth equals 1
       
       motorA.forward();       //move LEFT wheel in FORWARD direction
       motorB.forward();       //move RIGHT wheel in FORWARD direction
}

//command for moving robot BACKWARD
if (incoming_commands == '2'){ //if command over bluetooth equals 2
       
       motorA.reverse();       //move LEFT wheel in REVERSE direction
       motorB.reverse();       //move RIGHT wheel in REVERSE direction
}

//command for TURNING robot RIGHT 
if (incoming_commands == '3'){ //if command over bluetooth equals 3
       
       motorA.forward();       //move LEFT wheel in FORWARD direction
       motorB.reverse();       //move RIGHT wheel in REVERSE direction
       delay(500);             //wait for 0.2seconds
       motorA.forward();       //move LEFT wheel in FORWARD direction
       motorB.forward();       //move LEFT wheel in FORWARD direction
}

//command for TURNING robot LEFT
if (incoming_commands == '4'){ //if command over bluetooth equals 4
  
       motorA.reverse();       //move LEFT wheel in REVERSE direction
       motorB.forward();       //move RIGHT wheel in FORWARD direction
       delay(500);             //wait for 0.2seconds
       motorA.forward();       //move LEFT wheel in FORWARD direction
       motorB.forward();       //move RIGHT wheel in FORWARD direction
}

//command for moving robot BACKWARD
if (incoming_commands == '5'){ //if command over bluetooth equals 5
       
       motorA.stop();          //STOP LEFT wheel 
       motorB.stop();          //STOP RIGHT wheel 
 }

}
