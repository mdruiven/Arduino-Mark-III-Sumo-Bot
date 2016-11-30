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
int s = 20;
 
 
void setup() 
{ 
  servoL.attach(9);
  servoR.attach(10);
} 
 
void loop() 
{                              
   int disL=sensorL.getDistance();
   int disR=sensorR.getDistance();
   if (disL<20 && disR<20){
    allStop(50);
    turnLeft(100);
    allStop(50);
    forward(1000);
   }
   else
   {
    turnRight(100);
   }
        
} 

void forward(int d)
{
    servoL.write(zeroL+s);
    servoR.write(zeroR-s);
    delay(d);          
} 

void reverse(int d)
{
    servoL.write(zeroL-s);
    servoR.write(zeroR+s);
    delay(d);          
} 

void turnLeft(int d)
{
    servoL.write(zeroL-s);
    servoR.write(zeroR-s);
    delay(d);          
} 

void turnRight(int d)
{
    servoL.write(zeroL+s);
    servoR.write(zeroR+s);
    delay(d);          
} 

void allStop(int d){
  servoL.write(zeroL);
    servoR.write(zeroR);
    delay(d); 
}


