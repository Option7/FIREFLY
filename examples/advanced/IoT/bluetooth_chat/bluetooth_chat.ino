#include <SoftwareSerial.h>

SoftwareSerial bluetooth ( 10,11 ); //rx , tx



void setup() {
 // the setup function runs once when you press reset or power the board
 

  bluetooth.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
char message = bluetooth.read();
   while (bluetooth.available()==0)  
  {  
    Serial.write(message);
         //Wait for user input  
    } 
 message = Serial.read();
   while (Serial.available()==0)  
  {  
    bluetooth.write(message);
         //Wait for user input  
    } 
}
