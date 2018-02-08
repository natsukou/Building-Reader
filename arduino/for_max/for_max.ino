#include "EmonLib.h"
EnergyMonitor emon1;
double x = 0;
double y = 0;
double Irms = 0;

void setup() {
  Serial.begin(115200);             // 115200 is the default Arduino Bluetooth speed
  emon1.current(1, 111.1);
//  delay(600);
}
void loop() {
  if (Serial.available() > 0) {        // Check serial buffer for characters
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
      for(int pin = 0; pin <= 5; pin++){
        double Irms = emon1.calcIrms(1480);
        x = Irms;
        x = x * 10;
        sendValue(x);
        delay(100);
        }
//      if(int pin = 1){
//        double Irms = emon1.calcIrms(1480);
//        x = Irms;
//        x = x * 10;
//        sendValue(x);
//        delay(100);
//        }
//      for (int pin = 1; pin <= 1; pin++) {  // Read and send analog pins 0-5
//        x = analogRead(pin);
//        sendValue (x);
//        delay(100);
//      }
//      for (int pin = 2; pin <= 13; pin++) { // Read and send digital pins 2-13
//        x = digitalRead(pin);
//        sendValue (x);
//      }
      Serial.println();                 // Send a carriage returnt to mark end of pin data.
      delay (5);                        // add a delay to prevent crashing/overloading of the serial port
    }
  }
}
void sendValue (double x) {             // function to send the pin value followed by a "space".
//  y = x * 10.0;
  Serial.print(x);
  Serial.write(32);
}






