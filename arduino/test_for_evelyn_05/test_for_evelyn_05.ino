#include "EmonLib.h"
EnergyMonitor emon1;
double x = 0;
double Irms = 0;

void setup() {
  Serial.begin(115200);             // 115200 is the default Arduino Bluetooth speed
  emon1.current(1, 111.1);
  delay(600);
}
void loop() {
  if (Serial.available() > 0) {        // Check serial buffer for characters
//    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
        for (int pin = 0; pin <= 0; pin++) {
          x = analogRead(pin);
          sendValue(x);
        }
        if (int pin = 1) {
          double Irms = emon1.calcIrms(1480);
          x = Irms;
          sendValue(x);
        }
        for (int pin = 2; pin <= 5; pin++) {  // Read and send analog pins 0-5
          x = analogRead(pin);
          sendValue (x);
        }
        Serial.println();                 // Send a carriage returnt to mark end of pin data.
        delay(5);                        // add a delay to prevent crashing/overloading of the serial port
//    } //for r
  } //for serial available
} //for loop
void sendValue (double x) {             // function to send the pin value followed by a "space".
  Serial.print(x);
  Serial.write(32);
}






