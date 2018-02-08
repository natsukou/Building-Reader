#include "EmonLib.h"                   // Include Emon Library

const int numSensors = 5;
EnergyMonitor emon[numSensors];                   // Create an instance
double Irms[numSensors];

void setup()
{
  Serial.begin(115200);
  for (int i = 0; i <= numSensors; i++) emon[i].current(i, 111.1);
}

void loop()
{
  for (int i = 0; i <= numSensors; i++) {
      Irms[i] = emon[i].calcIrms(1480);  // Calculate Irms only
  }
  Serial.print(Irms[0]*100);
  Serial.println();
  delay(100);
}

