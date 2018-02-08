#include "EmonLib.h"
EnergyMonitor emon0, emon1, emon2, emon3, emon4;
double x = 0;
double Irms0, Irms1, Irms2, Irms3, Irms4;
int numSensors;

void setup() {
  Serial.begin(115200);             // 115200 is the default Arduino Bluetooth speed
  numSensors = 5;
  emon0.current(0, 111.1);
  emon1.current(1, 111.1);
  emon2.current(2, 111.1);
  emon3.current(3, 111.1);
  emon4.current(4, 111.1);
  establishContact();
  //  delay(600);
}
void loop() {
  if (Serial.available() > 0) {        // Check serial buffer for characters
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
      Irms0 = emon0.calcIrms(1480);
      Irms1 = emon1.calcIrms(1480);
      Irms2 = emon2.calcIrms(1480);
      Irms3 = emon3.calcIrms(1480);
      Irms4 = emon4.calcIrms(1480);
      sendValue(Irms0);
      sendValue(Irms1);
      sendValue(Irms2);
      sendValue(Irms3);
      sendValue(Irms4);
      Serial.println();                 // Send a carriage returnt to mark end of pin data.
      delay(5);                        // add a delay to prevent crashing/overloading of the serial port
    } //for r
  } //for serial available
} //for loop
void sendValue (double x) {             // function to send the pin value followed by a "space".
  Serial.print(x*100);
  Serial.write(32);
}
void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0");
    delay(100);
  }
}






