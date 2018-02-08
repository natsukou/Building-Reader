const int ledPin1 = 3; // or A0
const int ledPin2 = 5; // or A1
const int ledPin3 = 6; // or A2

int id = 0;  // byte sent from max
int maxData = 0;


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
      analogWrite(ledPin1, maxData);
    }

    if (id == 'B') {
      maxData = Serial.read();
      analogWrite(ledPin2, maxData);
    }

    if (id == 'C') {
      maxData = Serial.read();
      analogWrite(ledPin3, maxData);
    }
  }
}
