// 
//  Stille_Firmata.ino
//  Beispielcode Datenübertragung/Firmata
//  Seminar poetische Apparate, Interfacedesign, MKH
//  
//  Created by jens on 2012-11-07.
// 


#include <Firmata.h>

//  onAnalog wird von Firmata "automatisch" ausgeführt,
//  sobald eine entsprechende Nachricht empfange wurde.
void onAnalog(byte pin, int post_eingang) {

  // Mit dem Wert aus dem Posteingang "arbeiten"
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
  
  // Post wieder versenden
  Firmata.sendAnalog(0,post_ausgang);
}

void setup() {
  // Unser LED steckt auf der 12, damit es auch angeht, setze den Mode:
  pinMode(12,OUTPUT);
  
  // Binde die Funktion von Oben an das entsprechende Ereignis
  Firmata.attach(ANALOG_MESSAGE, onAnalog);
  
  // ... und starte die Firmata
  Firmata.begin(57600);
  
  // Ein Board muss den Prozess anstossen!
  // Kommentiere folgende Zeile für weitere Boards aus!
  Firmata.sendAnalog(0,1);
}

void loop() {
  // Damit die Firmata "läuft" brauchen wir die folgenden Zeilen; nicht mehr!
  while(Firmata.available()) {
    Firmata.processInput();
  }
}
