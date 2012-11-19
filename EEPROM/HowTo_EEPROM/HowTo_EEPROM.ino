// 
//  HowTo_EEPROM.ino
//  Beispielcode wie man Daten dauerhaft im Arduino
//  speichert.
//
//  EEPROM steht für:
//  Electrically Erasable Programmable Read-Only Memory
//
//  !! Achtung: das EEPROM hat nur eine begrenzte Anzahl
//              an Lese- und Schreibvorgängen!
//
//  Seminar poetische Apparate, Interfacedesign, MKH
//  
//  Created by jens on 2012-11-14.
// 

#include <EEPROM.h>

int boot_zaehler;
int zaehler_adresse = 0;

void setup() {

  // Verwende den digitalen Pin 2 als
  // Reset für den boot_zaehler. Schließe
  // dazu Pin 2 an GND an und starte das Board.
  pinMode(2,INPUT_PULLUP);
  if(digitalRead(2) == LOW) {
    boot_zaehler = 0;
  } 
  else {
    boot_zaehler = EEPROM.read(zaehler_adresse);
    boot_zaehler += 1;
  }
  
  EEPROM.write(zaehler_adresse, boot_zaehler);

  // Zur Bestätigung Blinke die Anzahl der Boots
  pinMode(12,OUTPUT); // Pin 12 soll Output sein!
  for (int i=0; i < boot_zaehler; i++) {
    digitalWrite(12, HIGH); 
    delay(250);
    digitalWrite(12, LOW);
    delay(250);
  }

}

void loop() {
  // tue in diesem Beispiel nichts...
}



