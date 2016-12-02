/* 
This was used to try and lessen the current drain when running the bot on just the 4 AA batteries.
In the end the bot seems more stable if the Arduino is supplied from a different voltage source (9 Volt battery) instead
of sharing the 4 AA batteries.
Mike Druiven, Nov 30, 2016
*/

#include <Servo.h>

Servo servoL;
Servo servoR;

int zeroL = 87; // adjust this value until servo is at rest
int zeroR = 91;
int L = 9;
int R = 10;
void setup()
{

}

void loop()
{
  forward(2000);
  reverse(2000);
  turnLeft(1000);
  turnRight(1000);
  allStop(3000);
}

void forward(int d)
{
  servoL.attach(L);
  servoR.attach(R);
  servoL.write(zeroL + 50);
  servoR.write(zeroR - 50);
  delay(d);
  servoL.detach();
  servoR.detach();
}

void reverse(int d)
{
  servoL.attach(L);
  servoR.attach(R);
  servoL.write(zeroL - 50);
  servoR.write(zeroR + 50);
  delay(d);
  servoL.detach();
  servoR.detach();
}

void turnLeft(int d)
{
  servoL.attach(L);
  servoR.attach(R);
  servoL.write(zeroL - 50);
  servoR.write(zeroR - 50);
  delay(d);
  servoL.detach();
  servoR.detach();
}

void turnRight(int d)
{
  servoL.attach(L);
  servoR.attach(R);
  servoL.write(zeroL + 50);
  servoR.write(zeroR + 50);
  delay(d);
  servoL.detach();
  servoR.detach();
}

void allStop(int d)
{
  servoL.detach();
  servoR.detach();
  delay(d);
}

