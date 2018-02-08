#include "EmonLib.h"

int numCycles = 10;
const int numSensors = 5;
EnergyMonitor emon[numSensors];
double Irms[numSensors];

void setup() {
  Serial.begin(115200);             // 115200 is the default Arduino Bluetooth speed
  for (int i = 0; i < numSensors; i++) {
    emon[i].current(i, 111.1);
  }
  establishContact();
  delay(600);
}
void loop() {
  if (Serial.available() > 0) {        // Check serial buffer for characters
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
      for (int i = 0; i < numSensors; i++) {
        Irms[i] = emon[i].calcIrms(106 * numCycles);
      }
      for (int i = 0; i < numSensors; i++) {
        if (Irms[i] > 300) {
          sendValue(30000);
        }
        else {
          sendValue(Irms[i]*100);
        }
      }
      Serial.println();                 // Send a carriage returnt to mark end of pin data.
      delay(5);                        // add a delay to prevent crashing/overloading of the serial port
    } //for r
  } //for serial available
} //for loop
void sendValue (double x) {             // function to send the pin value followed by a "space".
  Serial.print(x);
  Serial.write(32);
}
void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0");
    delay(100);
  }
}
