#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance

double x = 0;
double Irms = 0;

void setup()
{  
  Serial.begin(9600);
  
  emon1.current(1, 111.1);             // Current: input pin, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  Serial.println(Irms*230.0);         // Apparent power
//  Serial.print('\t');
//  Serial.println(Irms);          // Irms
}

