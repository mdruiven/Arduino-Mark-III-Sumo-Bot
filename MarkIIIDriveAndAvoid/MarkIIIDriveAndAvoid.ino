/* 
Drive and avoid walls
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
   int disR=sensorR.getDistance();
   if (disL<10){
    turnRight(400);
   }
   else if(disR<10){
    turnLeft(400);
   }
   else
   {
    forward(100);
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
