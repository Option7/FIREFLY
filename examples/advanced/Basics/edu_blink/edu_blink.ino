#include <FIREFLY.h>
   
LIGHT light (13);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  light.on();
  delay(1000);
  light.off();
  delay(1000);
}
