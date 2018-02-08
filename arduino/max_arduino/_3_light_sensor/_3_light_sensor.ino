const int sensorPin = A5; //A1

int sensorValue = 0;
int outputValue = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensorValue = analogRead(sensorPin);
  
  // map it to the range of the analog out:
  // convert 10 bit (0-1023) to 8 bit (0-255) to be easy control
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  Serial.println(outputValue);

  delay(2);

}
