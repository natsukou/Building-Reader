#include "EmonLib.h"
EnergyMonitor emon1;

double x = 0;
double Irms = 0;

void setup()
{
  Serial.begin(115200);             // 115200 is the default Arduino Bluetooth speed
  emon1.current(1, 111.1);
}

void loop()
{

  if (Serial.available() > 0) {        // Check serial buffer for characters

    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins

            for (int pin = 0; pin <= 5; pin++) {  // Read and send analog pins 0-5
              Irms = emon1.calcIrms(1480);
              x = Irms;
              sendValue (x);
            }
      
      
      
            for (int pin = 2; pin <= 13; pin++) { // Read and send digital pins 2-13
              Irms = emon1.calcIrms(1480);
              x = Irms;
              sendValue (x);
            }
      Serial.println();                 // Send a carriage returnt to mark end of pin data.
      delay (100);                        // add a delay to prevent crashing/overloading of the serial port

    }

    //  }
  }
}
void sendValue (double x) {             // function to send the pin value followed by a "space".
  Serial.println(x);
  Serial.write(32);
}



