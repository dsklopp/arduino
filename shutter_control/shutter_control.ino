/*
  Shutter control for Camera example
  Author: Dan Klopp (dsklopp@gmail.com)
  Please add youself to the authors list as you contribute code
  
  WARNING: This code has not been tested yet, waiting for other code
  contributions before testing.
 */
 
// Change led to the correct pin number when the device arrives
int led = 13; // currently the led

void setup() {                
  Serial.begin(9600)
  pinMode(led, OUTPUT);     
}

void loop() {
  //First read input if available
  int seconds = 5*60;
  while (Serial.available() > 0) {
    seconds = Serial.parseInt();
    //Flushing rest of line
    while(Serial.read() != -1)
  }
  
  digitalWrite(led, HIGH);
  delay(100);                // Flash shutter for 100 msec
  digitalWrite(led, LOW);
  delay(seconds*1000);               // Delay in seconds
  
}
