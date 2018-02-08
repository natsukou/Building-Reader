double x = 0;
int outputValue1 = 0;

void setup() {
  Serial.begin(115200);             // 115200 is the default Arduino Bluetooth speed
//  pinMode(buttonPin, INPUT_PULLUP);
//  pinMode(LED_BUILTIN, OUTPUT);
  delay(600);
}
void loop() {
  if (Serial.available() > 0) {        // Check serial buffer for characters
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
        for (int pin = 0; pin <= 5; pin++) {  // Read and send analog pins 0-5
          x = analogRead(pin);
          x = map(x,0,1023,0,255);
          sendValue (x);
        }
        Serial.println();                 // Send a carriage returnt to mark end of pin data.
        delay(5);                        // add a delay to prevent crashing/overloading of the serial port
    } //for r
  } //for serial available
} //for loop
void sendValue (double x) {             // function to send the pin value followed by a "space".
  Serial.print(x);
  //  Serial.print('\t');
  //  Serial.print(run);
  Serial.write(32);
}






