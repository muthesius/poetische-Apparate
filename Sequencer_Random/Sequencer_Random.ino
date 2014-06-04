#include <MIDI.h>

#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
  MIDI.begin(4);
}

void loop() {
  int schnell = analogRead(A0);
  schnell = map(schnell, 0, 1023, 250, 1000);
    
  int pitch = random(0,127);
  int velocity = random(0,127);
    
  digitalWrite(LED,HIGH);
  MIDI.sendNoteOn(pitch,velocity,1);
  
  delay(schnell/2);
  MIDI.sendNoteOff(pitch,0,1);
  digitalWrite(LED,LOW);    	
  delay(schnell/2);

}
