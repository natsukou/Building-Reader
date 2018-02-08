#include "EmonLib.h"
EnergyMonitor emon1;
double x = 0;
double Irms = 0;

int var = 0;
int old_var = 0;
int state = 0;
int buttonPin = 13;

void setup() {
  Serial.begin(115200);             // 115200 is the default Arduino Bluetooth speed
  emon1.current(1, 111.1);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(600);
}
void loop() {
  if (Serial.available() > 0) {        // Check serial buffer for characters
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
      var = digitalRead(buttonPin);
      if (var == HIGH && old_var == LOW) {
        state = 1 - state;
        delay(20);
      }
      if (var == LOW && old_var == HIGH) { 
        delay(20);
      }
      old_var = var;
      if (state == 0) {
//        digitalWrite(LED_BUILTIN, HIGH);
        for (int pin = 0; pin <= 0; pin++) {
          x = analogRead(pin);
          sendValue(x);
        }
        if (int pin = 1) {
          double Irms = emon1.calcIrms(1480);
          x = Irms;
          //        x = x * 10;
          sendValue(x);
        }
        for (int pin = 2; pin <= 5; pin++) {  // Read and send analog pins 0-5
          x = analogRead(pin);
          sendValue (x);
        }
        //      for (int pin = 2; pin <= 13; pin++) { // Read and send digital pins 2-13
        //        x = digitalRead(pin);
        //        sendValue (x);
        //      }
        Serial.println();                 // Send a carriage returnt to mark end of pin data.
        delay(5);                        // add a delay to prevent crashing/overloading of the serial port
      } //for state == 1
//      else digitalWrite(LED_BUILTIN, LOW);
    } //for r
  } //for serial available
} //for loop
void sendValue (double x) {             // function to send the pin value followed by a "space".
  //  y = x * 10.0;
  Serial.print(x);
  //  Serial.print('\t');
  //  Serial.print(run);
  Serial.write(32);
}






