int led = 3;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is


// the setup routine runs once when you press reset:
void setup() {

  Serial.begin(9600);
  
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  if(Serial.available()) {
    brightness = Serial.read();

  // set the brightness of pin 9:
    analogWrite(led, brightness);
  }

}
