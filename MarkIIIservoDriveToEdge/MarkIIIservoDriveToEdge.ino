/* 
Drives the bot forward until the surface contrast changes from black to white
and then turns away from the edge if the approach is shallow
or stops, backs up, turns away from the edge if the approach is near 90 degrees.
Mike Druiven Nov 30, 2016
*/ 

#include <Servo.h> 
 
Servo servoL;
Servo servoR;
 
int zeroL = 87; // adjust this value until servo is at rest
int zeroR = 91; 
int qrbL=A2; // The downward facing line sensors are connected to A0, A1 and A2
int qrbC=A1;
int qrbR=A0;
int spd = 100; // A value which when added to zeroL and subtracted from zeroR will cause the servo to move at top speed.
 
void setup() 
{ 
  servoL.attach(9); // The servos are attached to 9 and 10
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

