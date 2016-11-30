/* Sweep Mark III servos
Test the Mark III servos
*/ 

#include <Servo.h> 
 
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
   forward(2000);
   reverse(2000);
   turnLeft(1000);
   turnRight(1000);
   allStop(3000);        
} 

void forward(int d)
{
    servoL.write(zeroL+50);
    servoR.write(zeroR-50);  
    delay(d);
    servoL.write(zeroL);
    servoR.write(zeroR);
    delay(15);        
} 

void reverse(int d)
{
    servoL.write(zeroL-50);
    servoR.write(zeroR+50); 
    delay(d); 
    servoL.write(zeroL);
    servoR.write(zeroR);         
} 

void turnLeft(int d)
{
    servoL.write(zeroL-50);
    servoR.write(zeroR-50); 
    delay(d); 
    servoL.write(zeroL);
    servoR.write(zeroR);         
} 

void turnRight(int d)
{
    servoL.write(zeroL+50);
    servoR.write(zeroR+50); 
    delay(d); 
    servoL.write(zeroL);
    servoR.write(zeroR);         
} 

void allStop(int d)
{
    servoL.write(zeroL);
    servoR.write(zeroR); 
    delay(d);         
}

