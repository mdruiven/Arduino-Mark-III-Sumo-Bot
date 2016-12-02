// Mike Druiven, Nov 30, 2016
// code to run Arduino Mark III robot with Sharp IR sensors
#include <Servo.h>
#include <SharpIR.h>
SharpIR sensor(GP2Y0A21YK0F, A4); // The right IR sensor is connected to A4 or analog 4. Change to A3 to check the left sensor.
void setup() {
Serial.begin(9600);
}
void loop() {
  delay (2000);
  int dis=sensor.getDistance(); // Get a sensor value every 2 seconds
  Serial.println(dis); //  and print it out on the serial monitor.

}
