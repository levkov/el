#include <AltSoftSerial.h>
AltSoftSerial impSerial(8, 9); // RX on 8, TX on 9
// remember: Arduino TX = Imp RX!
int led = 13;            // led pin number
 
void setup() {
  //pins 0 (RX) and 1 (TX)
  Serial.begin(9600);    // configure serial
  // set the data rate for the SoftwareSerial port
  impSerial.begin(9600);
  pinMode(led, OUTPUT);  // configure LED pin
  digitalWrite(led, 0);  // turn LED off
}
 
void loop() {
  int b = 0;
  // if there's data available
  if (impSerial.available () > 0) {
    // read a byte
    b = impSerial.read();
    if (b == 0x00) {
      digitalWrite(led, LOW);
      impSerial.write(0x10);
    } else if (b == 0x01) {
      digitalWrite(led, HIGH);
      impSerial.write(0x11);
    }
  }
}
