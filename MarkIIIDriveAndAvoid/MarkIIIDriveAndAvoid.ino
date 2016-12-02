/* 
Drive and avoid walls
Mike Druiven Nov 30, 2016
*/ 

#include <Servo.h> 
#include <SharpIR.h>
SharpIR sensorL(GP2Y0A21YK0F, A3);
SharpIR sensorR(GP2Y0A21YK0F, A4);
 
Servo servoL;
Servo servoR;
 
int zeroL = 87; // adjust this value until servo is at rest
int zeroR = 91;
 
 
void setup() 
{ 
  servoL.attach(9);
  servoR.attach(10);
} 
 
void loop() 
{                              
   int disL=sensorL.getDistance();
   int disR=sensorR.getDistance(); // Get the left and right ir sensor values.
   if (disL<10){ // If the left sensor drops below 10 it is very close to something.
    turnRight(400); // So spin right.
   }
   else if(disR<10){ // If the right sensor drops below 10 it is very close to something.
    turnLeft(400); // So spin left.
   }
   else
   {
    forward(100);  //  Otherwise drive forward.
   }
        
} 

void forward(int d)
{
    servoL.write(zeroL+50);
    servoR.write(zeroR-50);
    delay(d);          
} 

void reverse(int d)
{
    servoL.write(zeroL-50);
    servoR.write(zeroR+50);
    delay(d);          
} 

void turnLeft(int d)
{
    servoL.write(zeroL-50);
    servoR.write(zeroR-50);
    delay(d);          
} 

void turnRight(int d)
{
    servoL.write(zeroL+50);
    servoR.write(zeroR+50);
    delay(d);          
} 
