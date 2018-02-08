const int buttonPin = 8;
const int buttonPin1 = 9;
const int buttonPin2 = 5;

int val = 0;
int val1 = 0;
int val2 = 0;


void setup() {
    // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

   val = digitalRead(buttonPin);
   val1 = digitalRead(buttonPin1);
   val2 = digitalRead(buttonPin2);

   // if sending multiple messages to max, 
   // it needs to put " " message between the values.
   
   Serial.print(val);
   Serial.print(" ");
   
   Serial.print(val1);
   Serial.print(" ");

   // the last messag
   Serial.println(val2);
  
  delay(2);

}                                                                             
