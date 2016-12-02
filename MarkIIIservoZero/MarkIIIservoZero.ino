/* 
Continuous Rotation Servos should be at rest with value 90. 
Adjust the zeroL and zeroR values until the robot stops moving.
*/ 

#include <Servo.h> 
 
Servo servoL;
Servo servoR;
 
int zeroL = 87; // adjust this value until servo is at rest
int zeroR = 91; 
 
void setup() 
{ 
  servoL.attach(9); // Servos attached to 9 and 10.
  servoR.attach(10);
} 
 
void loop() 
{                              
    servoL.write(zeroL);
    servoR.write(zeroR);          
   
} 

