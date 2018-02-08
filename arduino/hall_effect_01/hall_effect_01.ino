const int hallPin = A1;
const int ledPin = 13;
int sensorVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(hallPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorVal = analogRead(hallPin);
  if(sensorVal > 300) digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);
  Serial.print(sensorVal);
  Serial.print('\t');
  Serial.println(sensorVal);
  delay(100);
}



