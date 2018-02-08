const int ledPin = 13;

int maxData = 0;

void setup() {
  Serial.begin(9600);

  // init output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {
    maxData = Serial.read();
    Serial.println(maxData);
  }

  if (maxData == 1) {
    digitalWrite(ledPin, HIGH);   // turn led on
  }
  if (maxData == 0) {
    digitalWrite(ledPin, LOW);   // turn led off
  }
}
