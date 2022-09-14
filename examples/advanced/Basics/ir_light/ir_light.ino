#include <FIREFLY.h>
IR ir(2);
LIGHT light(13);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
if(ir.detected()){light.on();}
if(ir.undetected()){light.off();}



}
