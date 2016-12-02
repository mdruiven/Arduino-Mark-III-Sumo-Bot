/*
 Test Arduino Mark III LEDs
 */

void setup() {                
  // These are dignostic LEDs which can be used to give a visual signal of an event.
  pinMode(11, OUTPUT); // The LEDs are connected to pins 11, 12 and 13.
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);     
}
// Flash the LEDs in sequence
void loop() {
  for (int x = 11; x<14;x++){
  digitalWrite(x, HIGH);  
  delay(100);              
  digitalWrite(x, LOW);    
  delay(100);     
  }         
}
