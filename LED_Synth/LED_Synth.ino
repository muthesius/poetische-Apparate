#include <MIDI.h>

int ledPin = 9;

void HandleNoteOn(byte channel, byte pitch, byte velocity)
{
  analogWrite(ledPin, velocity);  
}

void HandleNoteOff(byte channel, byte pitch, byte velocity)
{
  analogWrite(ledPin, 0);  
}

// -----------------------------------------------------------------------------

void setup()
{
  pinMode(ledPin, OUTPUT); // eventuell notwendig...
  
    MIDI.begin(MIDI_CHANNEL_OMNI);    
    MIDI.setHandleNoteOn(HandleNoteOn);  // Put only the name of the function
    MIDI.setHandleNoteOff(HandleNoteOff);  // Put only the name of the function
}


void loop()
{
    MIDI.read();
}
