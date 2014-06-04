#include <MIDI.h>

void HandleNoteOn(byte channel, byte pitch, byte velocity)
{
}

void HandleNoteOff(byte channel, byte pitch, byte velocity)
{
}

// -----------------------------------------------------------------------------

void setup()
{
    MIDI.begin(MIDI_CHANNEL_OMNI);    
    MIDI.setHandleNoteOn(HandleNoteOn);  // Put only the name of the function
    MIDI.setHandleNoteOff(HandleNoteOff);  // Put only the name of the function
}


void loop()
{
    MIDI.read();
}
