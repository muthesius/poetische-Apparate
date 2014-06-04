#include <MIDI.h>


int LED = 11;


void HandleNoteOn(byte channel, byte pitch, byte velocity) { 
  analogWrite(LED, velocity);
}

void HandleNoteOff(byte channel, byte pitch, byte velocity) { 
  analogWrite(LED, 0);
}


void setup() {
  pinMode(LED,OUTPUT);
  analogWrite(LED, 0);
  
  MIDI.begin(MIDI_CHANNEL_OMNI);    
  
  MIDI.setHandleNoteOn( HandleNoteOn );
  MIDI.setHandleNoteOff( HandleNoteOff );
}


void loop() {
  MIDI.read();

}
