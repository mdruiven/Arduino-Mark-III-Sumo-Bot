/* 
Drives the bot forward until the surface contrast changes from black to white
and then turns away from the edge if the approach is shallow
or stops, backs up, turns away from the edge if the approach is near 90 degrees.
Turns towards close objects. Uses detectEdge() method. forward(d) method also contains
detectEdge() method so that it can check for the edge while pushing an opponent.
Mike Druiven March 22, 2017
*/ 

#include <Servo.h> 
#include <SharpIR.h>
SharpIR sensorL(GP2Y0A21YK0F, A3); // setup IR sensors
SharpIR sensorR(GP2Y0A21YK0F, A4);
 
Servo servoL; // setup servos
Servo servoR;
 
int zeroL = 89; // adjust this value until servo is at rest
int zeroR = 98; 
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
   int disL=sensorL.getDistance();
   int disR=sensorR.getDistance(); //Get the left and right ip sensor values.

   detectEdge();
   
   if (disL<20 && disR<20){ //Look for an object within range 20.
     // If an object is detected keep driving.
    forward(200); // Now run at the object for 1/5th of a second.
   }
   else if (disL<20){ //Look for an object within range 20 on the left.
    turnLeft(100); // If an object is detected turn left.
    forward(200); // Now run at the object for 1/5th of a second.
   }
   else if (disR<20){ //Look for an object within range 20 on the right.
    turnRight(100); // If an object is detected turn right.
    forward(200); // Now run at the object for 1/5th of a second.
   } 
   else
   {
    forward(100); // Otherwise keep running straight for 1/10th of a second.
   }
} 

void detectEdge(){
   int Lval = analogRead (qrbL);
   int Cval = analogRead (qrbC);
   int Rval = analogRead (qrbR);
   int turn = 500; // low values will circle near the edge
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
   reverse(2000);      // turning is not enough so back away first
   turnLeft(500);
   }
}

void forward(int d)
{
    int startTime = millis();
    int endTime = millis();
    while (endTime<(startTime + d)){
      servoL.write(zeroL+spd);
      servoR.write(zeroR-spd);  
      delay(10); //so we can look for the edge every 1/100th of a second
      detectEdge();
      endTime = millis(); //reset endTime so that eventually it exceeds startTime + d
   }      
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

