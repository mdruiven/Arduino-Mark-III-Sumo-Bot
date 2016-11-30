/* Sweep Mark III servos
Test the Mark II servos
*/ 

#include <Servo.h> 
 
Servo servoL;
Servo servoR;
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  servoL.attach(9);
  servoR.attach(10);
} 
 
void loop() 
{ 
  for(pos = 0; pos <= 180; pos += 1) 
  {                                
    servoL.write(pos);          
    delay(15);                      
  } 
  for(pos = 180; pos>=0; pos-=1)     
  {                                
    servoL.write(pos);               
    delay(15);                       
  } 
  for(pos = 0; pos <= 180; pos += 1) 
  {                                
    servoR.write(pos);          
    delay(15);                      
  } 
  for(pos = 180; pos>=0; pos-=1)     
  {                                
    servoR.write(pos);               
    delay(15);                       
  } 
} 

