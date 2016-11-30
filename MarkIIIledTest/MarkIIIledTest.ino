/*
 Test Arduino Mark III LEDs
 */

void setup() {                

  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);     
}

void loop() {
  for (int x = 11; x<14;x++){
  digitalWrite(x, HIGH);  
  delay(100);              
  digitalWrite(x, LOW);    
  delay(100);     
  }         
}
