/* Sweep Mark III servos
Test the Mark III servos
*/ 

#include <Servo.h> 
 
Servo servoL;
Servo servoR;
 
int zeroL = 87; // adjust this value until servo is at rest
int zeroR = 91; 
int qrbL=A2;
int qrbC=A1;
int qrbR=A0;
int spd = 100;
 
void setup() 
{ 
  servoL.attach(9);
  servoR.attach(10);
} 
 
void loop() 
{                              
   int Lval = analogRead (qrbL);
   int Cval = analogRead (qrbC);
   int Rval = analogRead (qrbR);
   int turn = 150; // low values will circle near the edge
                  // higher values will turn in more
   
   if(Lval<700 && Cval > 700){
    turnRight(turn); // approaching edge from the left
   }
   else if (Lval<700 && Cval<700){
   allStop(50);     // approaching edge almost straight on
   reverse(200);    // turning is not enough so back away first
   turnRight(500);
   }
   else if (Rval<700 && Cval>700){
    turnLeft(turn);  // approaching edge from the right
   }
   else if (Rval<700 && Cval<700){
   allStop(50);       // approaching edge almost straight on
   reverse(200);      // turning is not enough so back away first
   turnLeft(500);
   }
   else{
    forward(100);
   }
} 

void forward(int d)
{
    servoL.write(zeroL+spd);
    servoR.write(zeroR-spd);  
    delay(d);
    //servoL.write(zeroL);
    //servoR.write(zeroR);
    //delay(15);        
} 

void reverse(int d)
{
    servoL.write(zeroL-spd);
    servoR.write(zeroR+spd); 
    delay(d); 
    servoL.write(zeroL);
    servoR.write(zeroR);         
} 

void turnLeft(int d)
{
    servoL.write(zeroL-spd);
    servoR.write(zeroR-spd); 
    delay(d); 
    servoL.write(zeroL);
    servoR.write(zeroR);         
} 

void turnRight(int d)
{
    servoL.write(zeroL+spd);
    servoR.write(zeroR+spd); 
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

