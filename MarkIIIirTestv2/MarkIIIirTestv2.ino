// Mike Druiven Nov 30, 2016
// code to run Arduino Mark III robot with Sharp IR sensors
#include <SharpIR.h>
SharpIR sensorL(GP2Y0A21YK0F, A3); // Left sensor connected to A3
SharpIR sensorR(GP2Y0A21YK0F, A4); // Right sesnor connected to A4
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
  // Print the left and right sensor values onto the serial monitor
}
