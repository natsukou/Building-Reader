const int sensorPin1 = A1;
const int sensorPin2 = A2; // select the input pin for the potentiometer
int sensorValue1 = 0;
int sensorValue2 = 0;// variable to store the value coming from the sensor
int outputValue1 = 0;
int outputValue2 = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue1 = analogRead(sensorPin1);
//  sensorValue2 = analogRead(sensorPin2);
      outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
//      outputValue2 = map(sensorValue2,0,1023,0,255);
      Serial.println(outputValue1);
//      Serial.print(" ");
//      Serial.println(outputValue2);
    delay(100);

}
