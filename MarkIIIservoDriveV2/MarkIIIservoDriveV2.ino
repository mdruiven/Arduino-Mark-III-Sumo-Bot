/* Sweep Mark III servos
Test the Mark III servos
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

