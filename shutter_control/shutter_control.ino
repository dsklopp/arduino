/*
  Shutter control for Camera example
  Author: Dan Klopp (dsklopp@gmail.com)
  Please add youself to the authors list as you contribute code
  
  Code is updateable within intervals over a serial connection
  connect likeso: screen /dev/ttyACM0 9600
  If a new time is given, the current delay is aborted, a photo taken,
  and the loop restarted.
 */
 
#include <LiquidCrystal.h> 

// Change led to the correct pin number when the device arrives
int led = 13; // currently the led
int cameraShutter = 2;
LiquidCrystal lcd(7,8,9,10,11,12);
int seconds = 600*1; // default shutter time

void setup() {                
  Serial.begin(9600);
  lcd.begin(16,1);
  pinMode(led, OUTPUT);
}

void loop() {
  lcd.clear();
  lcd.print(seconds);
  lcd.print(" seconds");
  digitalWrite(led, HIGH);
  digitalWrite(cameraShutter, HIGH);
  delay(1000);                // Flash shutter for 100 msec
  digitalWrite(cameraShutter, LOW);
  digitalWrite(led, LOW);

  int iter=0;
  if (seconds < 1) { seconds=1; }
  while (iter < seconds) {
    iter++;
    if (Serial.available() > 0) {
      seconds = Serial.parseInt();
      //Flushing rest of line
      while(Serial.read() != -1) {}
      break;
    }
    delay(1000);
  }

}
