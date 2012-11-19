/*
 * Beispiel aus dem Seminar: Fotowiderstand und Servo
 *
 * (basiert auf dem AnalogInOut_Serial Beispiel)
 *
 * Der Wert des Fotowiderstandes wird auf eine Gradzahl
 * für den Servo umgerechnet und an diesen geschickt.
 * In einem 2. Schritt wurde ein Button eingesetzt und
 * der Wert nur auf Drücken des Buttons gelesen und 
 * der Servo gestellt.
 *
 */

// Wichtig: die Servo Library müssen wir extra einbinden!
#include <Servo.h>

// Da wir einen Servo anschließen wollen, brauchen wir einen:
Servo myservo;

// Der Pin an dem der Fotowiderstand hängt:
const int analogInPin = A0;

// Für besseren Code zwei Variablen für die Werte:
int sensorValue = 0;
int outputValue = 0;

// Um den Button mit Statuswechsel zu beobachten,
// brauchen wir 3 Variablen:
const int button = 2; // Die Pinnummer (kann konstant sein)
int state  = 0; // Den aktuellen Status
int last_state = 0; // und einen Puffer für den Status davor


void setup() {
  // Die Kommunkation mit dem Rechner initieren:
  Serial.begin(9600); 
  
  // Der Button vorbereiten
  // und für einfachere Verkabelung als PULL_UP defnieren
  pinMode(button,INPUT_PULLUP);
  
  // Den Servo starten:
  myservo.attach(9);
}

void loop() {
  // Hier beginnt der Code, um den Statuswechsel des Buttons
  // zu erfassen:
  // 1. Lese den Status des Pins in eine globale Variable
  state = digitalRead(button);
  // 2. Hat sich der Status seit dem letzten Durchgang geändert?
  if ( state != last_state ) {
    // 3. Ja, hat sich geändert. Ist er nun LOW?
    if ( state == LOW ) {
      // Hier wurde der Button also runtergedrückt.
      // Also der Code für den Wechsel von HIGH nach LOW
      state = digitalRead(button);
      sensorValue = analogRead(analogInPin);            
      outputValue = map(sensorValue, 0, 1023, 0, 179);  
      myservo.write(outputValue);
    } else if (state == HIGH) {
      // Hier der Code für den Wechsel von LOW nach HIGH
      // ... kein Bedarf in diesem Bespiel.
    }
  }
  last_state = state;

  // Zur Kontrolle schicken wir die Werte per Serial
  // an den Computer. Öffne dazu den Serial Monitor
  // von Arduino.
  Serial.print("sensor");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  delay(2); // Nur ein bisschen bremsen, damit sich Serial nicht "verschluckt".
}

