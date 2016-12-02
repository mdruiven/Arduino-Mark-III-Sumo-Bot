/* 
Robot spins until an object about the same size as itself is placed nearby.
The Robot will then move towards the object.
Mike Druiven Nov. 30, 2016
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
   int disR=sensorR.getDistance(); //Get the left and right ip sensor values.
   if (disL<20 && disR<20){ //Look for an object within range 20.
    allStop(50); // If an object is detected stop spinning.
    turnLeft(100); // Since it was spinning to the right it needs to turn back towards the object a bit.
    allStop(50);
    forward(1000); // Now run at the object.
   }
   else
   {
    turnRight(100); // Otherwise keep spinning to the right.
   }
        
} 

void forward(int d) // Drive forward for d milliseconds.
{
    servoL.write(zeroL+s);
    servoR.write(zeroR-s);
    delay(d);          
} 

void reverse(int d)  //  Drive reverse for d milliseconds
{
    servoL.write(zeroL-s);
    servoR.write(zeroR+s);
    delay(d);          
} 

void turnLeft(int d) // Spin to the left for d milliseconds.
{
    servoL.write(zeroL-s);
    servoR.write(zeroR-s);
    delay(d);          
} 

void turnRight(int d) // Spin to the right for d milliseconds.
{
    servoL.write(zeroL+s);
    servoR.write(zeroR+s);
    delay(d);          
} 

void allStop(int d){ // Stop moving for d milliseconds.
  servoL.write(zeroL);
    servoR.write(zeroR);
    delay(d); 
}


