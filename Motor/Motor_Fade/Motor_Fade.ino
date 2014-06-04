/*
  Simple PWN fade example
  --------------------------
  
  Fades anything PWM capable on pin 9 up & down...
  
  
  License: GPL
  Author:  Jens Alexander Ewald, ewald@muthesius.de
           Muthesius Academy of Fine Arts & Design, 2014
  Course:  Poetische Apparate, advanced Arduino, SS 2014  
 */

const int MOTOR_PIN  = 9;
const int FADE_SPEED = 200;

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);  
}

void loop() {
  
  // Fade up...
  for (int speed_value=0; speed_value <= 255; speed_value++) {
    analogWrite(MOTOR_PIN, speed_value);
    delay(FADE_SPEED);
  }
  
  // ... and fade down ...
  for (int speed_value=255; speed_value >= 0; speed_value--) {
    analogWrite(MOTOR_PIN, speed_value);
    delay(FADE_SPEED);
  }

}
