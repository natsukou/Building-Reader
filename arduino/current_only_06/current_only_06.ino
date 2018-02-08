#include "EmonLib.h"                   // Include Emon Library

const int numSensors = 5;
EnergyMonitor emon0,emon1,emon2,emon3,emon4,emon5;                   // Create an instance
double Irms0,Irms1,Irms2,Irms3,Irms4;

void setup()
{
  Serial.begin(115200);
  emon0.current(0,111.1);
//  emon1.current(1,111.1);
//  emon2.current(2,111.1);
//  emon3.current(3,111.1);
//  emon4.current(4,111.1);
}

void loop()
{
  Irms0 = emon0.calcIrms(1480);
//  Irms1 = emon1.calcIrms(1480);
//  Irms2 = emon2.calcIrms(1480);
//  Irms3 = emon3.calcIrms(1480);
//  Irms4 = emon4.calcIrms(1480);
  Serial.println(Irms0*100);
//  Serial.print('\t');
//  Serial.print(Irms1*100);
//  Serial.print('\t');
//  Serial.print(Irms2*100);
//  Serial.print('\t');
//  Serial.print(Irms3*100);
//  Serial.print('\t');
//  Serial.print(Irms4*100);
//  Serial.print('\t');
//  Serial.println();
  delay(5);
}

