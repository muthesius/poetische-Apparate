#include <MIDI.h>

#define LED 13   		// LED pin on Arduino board


void setup() {
  pinMode(LED, OUTPUT);
  MIDI.begin(4);            	// Launch MIDI with default options
				// input channel is set to 4
}

void loop() {
  int schnell = analogRead(A0);
  schnell = map(schnell, 0, 1023, 250, 1000);
  
  int velocity = analogRead(A1);
  velocity = map(velocity, 0, 1023, 0, 127);
    
  digitalWrite(LED,HIGH);     // Blink the LED
  MIDI.sendNoteOn(42,velocity,1);  // Send a Note (pitch 42, velo 127 on channel 1)
  
  
  
  
  delay(schnell/2);		// Wait for a second
  MIDI.sendNoteOff(42,0,1);   // Stop the note
  digitalWrite(LED,LOW);    	
  delay(schnell/2);		// Wait for a second
  
}
