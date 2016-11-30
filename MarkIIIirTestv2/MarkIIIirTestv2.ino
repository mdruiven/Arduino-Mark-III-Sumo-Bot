
// code to run Arduino Mark III robot with Sharp IR sensors
#include <SharpIR.h>
SharpIR sensorL(GP2Y0A21YK0F, A3);
SharpIR sensorR(GP2Y0A21YK0F, A4);
void setup() {
Serial.begin(9600);
}
void loop() {
  delay (2000);
  int disL=sensorL.getDistance();
  int disR=sensorR.getDistance();
  Serial.print(disL);
  Serial.print("   ");
  Serial.println(disR);

}
