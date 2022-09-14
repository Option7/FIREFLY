#include <FIREFLY.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth ( 10,11 ); //rx , tx
LIGHT          light     (13);


void setup() {
 // the setup function runs once when you press reset or power the board
 

  bluetooth.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
char incoming_command = bluetooth.parseInt();
   while (bluetooth.available()==0)  
  {  
    //Wait for user input  
    } 
   if  (  incoming_command == '1' ){
      light.on();    // turn the LED on                   
   } 
    
   if  (  incoming_command == '3' ){
      light.off();    // turn the LED off                 
   } 
}
