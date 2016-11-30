/* Sweep Mark III servos
Test the Mark II servos
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
    servoL.write(zeroL);
    servoR.write(zeroR);          
   
} 

