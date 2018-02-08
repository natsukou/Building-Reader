const int buttonPin = 9; // or A0

int val = 0;

void setup() {
    // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  val = digitalRead(buttonPin);
  Serial.println(val);

  delay(2);

}
