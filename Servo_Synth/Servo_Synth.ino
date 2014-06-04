#include <MIDI.h>
#include <Servo.h> 

int LED = 11;
int SERVO = 9;

Servo myservo;

void HandleNoteOn(byte channel, byte pitch, byte velocity) { 
  analogWrite(LED, velocity);
  myservo.write(pitch);
}

void HandleNoteOff(byte channel, byte pitch, byte velocity) { 
  analogWrite(LED, 0);
  // leave the servo where it was!
}


void setup() {
  myservo.attach(9);
  
  pinMode(LED,OUTPUT);
  analogWrite(LED, 0);
  
  MIDI.begin(MIDI_CHANNEL_OMNI);    
  
  MIDI.setHandleNoteOn( HandleNoteOn );
  MIDI.setHandleNoteOff( HandleNoteOff );
}


void loop() {
  MIDI.read();

}
