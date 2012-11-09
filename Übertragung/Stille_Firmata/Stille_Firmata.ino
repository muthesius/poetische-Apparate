#include <Firmata.h>

void onAnalog(byte pin, int post_eingang) {

  // blinken
  for(int i=0; i < post_eingang; i++) {
    digitalWrite(12,HIGH);
    delay(500);
    digitalWrite(12,LOW);
    delay(500);
  }
  
  // Post "bearbeiten"
  int post_ausgang;
  if (post_eingang > 10) {
    post_ausgang = 1;
  } else {
    post_ausgang = post_eingang+1;
  }
  
  Firmata.sendAnalog(0,post_ausgang);
}

void setup() {
  pinMode(12,OUTPUT);
  Firmata.attach(ANALOG_MESSAGE, onAnalog);
  Firmata.begin(57600);
  Firmata.sendAnalog(0,1);
}

void loop() {
  while(Firmata.available()) {
    Firmata.processInput();
  }
}
