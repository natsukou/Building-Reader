#include "EmonLib.h"

const int numSensors = 5;

int numCycles = 5;

EnergyMonitor emon[numSensors];
double Irms[numSensors];

void setup() {
  Serial.begin(115200);             // 115200 is the default Arduino Bluetooth speed
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  for (int i = 0; i < numSensors; i++) {
    emon[i].current(i, 111.1);
  }
  while (millis() < 5000) {               //calibrate during the first five seconds
    for (int i = 0; i < numSensors; i++) {
      Irms[i] = emon[i].calcIrms(106 * numCycles);
      if (Irms[i] > sensorMax) {          //record the maximum sensor value
        sensorMax = Irms[i];
      }
      if (Irms[i] < sensorMin) {          //record the minimum sensor value
        sensorMin = Irms[i];
      }
      Serial.print(Irms[i]);
      Serial.print(sensorMax);
      Serial.print(sensorMin);
    }
    
  }
  digitalWrite(13, LOW);
  establishContact();
  delay(600);
}
void loop() {
  if (Serial.available() > 0) {        // Check serial buffer for characters
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
      for (int i = 0; i < numSensors; i++) {
        Irms[i] = emon[i].calcIrms(106 * numCycles);
        Irms[i] = map(Irms[i], sensorMin, sensorMax, 0, 255);
        Irms[i] = constrain(Irms[i], 0, 255);
      }
      for (int i = 0; i < numSensors; i++) {
        sendValue(Irms[i]);
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
