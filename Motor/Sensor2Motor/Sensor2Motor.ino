/*
  Simple PWN control example
  --------------------------
  
  The sensor value of the analog pin 0
  is used to control the PWM speed of pin 9.
  
  
  License: GPL
  Author:  Jens Alexander Ewald, ewald@muthesius.de
           Muthesius Academy of Fine Arts & Design, 2014
  Course:  Poetische Apparate, advanced Arduino, SS 2014  
 */

const int MOTOR_PIN  = 9;
const int SENSOR_PIN = A0;

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);  
}

void loop() {
  int sensor_value = analogRead(SENSOR_PIN);
  int speed_value  = map(sensor_value, 0, 1023, 0, 255);
  speed_value = constrain(speed_value, 0, 255);
  analogWrite(MOTOR_PIN, speed_value);
}
