const int ledPin1 = 3; // 3
const int ledPin2 = 5; // 5
const int ledPin3 = 6; // 6

int id = 0; 
int maxData = 0; // byte sent from max


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  // init input and output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    id = Serial.read();
    //Serial.println(id);

    delay(10);

    if (id == 'A') {
      maxData = Serial.read();
      //        Serial.print("A");
      //        Serial.println(maxData);

      if (maxData == 1) {
        digitalWrite(ledPin1, HIGH);   // turn led on
      }
      if (maxData == 0) {
        digitalWrite(ledPin1, LOW);    // turn led off
      }
    }

    if (id == 'B') {
      maxData = Serial.read();
      //        Serial.print("B");
      //        Serial.println(maxData);

      if (maxData == 1) {
        digitalWrite(ledPin2, HIGH);   // turn led on
      }
      if (maxData == 0) {
        digitalWrite(ledPin2, LOW);    // turn led off
      }
    }

    if (id == 'C') {
      maxData = Serial.read();
      //        Serial.print("C");
      //        Serial.println(maxData);

      if (maxData == 1) {
        digitalWrite(ledPin3, HIGH);   // turn led on
      }
      if (maxData == 0) {
        digitalWrite(ledPin3, LOW);    // turn led off
      }
    }
  }
}
