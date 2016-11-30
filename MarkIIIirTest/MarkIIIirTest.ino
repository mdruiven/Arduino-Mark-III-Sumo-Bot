
// code to run Arduino Mark III robot with Sharp IR sensors
#include <Servo.h>
#include <SharpIR.h>
SharpIR sensor(GP2Y0A21YK0F, A4);
void setup() {
Serial.begin(9600);
}
void loop() {
  delay (2000);
  unsigned long pepe1=millis();
  int dis=sensor.getDistance();
  Serial.println(dis);

}
