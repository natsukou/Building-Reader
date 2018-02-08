#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance

double Irms = 0;

void setup()
{  
  Serial.begin(115200);
  
  emon1.current(1, 111.1);             // Current: input pin, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
//  Irms = analogRead(A1);
  Serial.print(Irms);          // Irms
  Serial.print('\t');
  Serial.println(Irms*100);
  delay(100);
}

