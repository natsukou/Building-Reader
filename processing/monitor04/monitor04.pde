import processing.serial.*;
Serial myPort;
int numSensors = 5;
float[] sensors;
int x;
float[] in;
float[] in_;
int[] axis;

float multiplier;

void setup() {
  size(600, 800); 
  background(0);
  //frameRate(60);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[3], 115200);
  myPort.bufferUntil('\n');
  multiplier = 1;
  sensors = new float[numSensors];
  in = new float[numSensors];
  axis = new int[numSensors];
  for (int i=0; i<numSensors; i++) {
    axis[i] = 150 * (i+1);
  }
}
void draw() {
  //start of monitor
  stroke(0);
  int offset = 100;
  line(x+offset, 0, x+offset, height);
  line(x+2+offset, 0, x+2+offset, height);
  stroke(0, 255, 0);
  for (int i =0; i<5; i++) {
    if (in[i]>140/multiplier) in[i] = 140/multiplier;
    line(x+offset, axis[i], x+offset, axis[i]-in[i]*multiplier);
  }
  x+=2;
  if (x > width-offset) {
    x = 0;
  }
  delay(300);
  //text("100",10,height-10);
  //pushStyle();
  //stroke(255);
  //line(50,height-10,offset,height-10);
  //popStyle();
  //end of monitor
  //saveFrame("k08_####.png");
}
void serialEvent(Serial myPort) {
  String myString; //definition of series of string from arduino            //if port 0 is available
  try {                             //if string is available
    myString = myPort.readStringUntil('\n');
    myString = trim(myString);
    sensors = float(split(myString, " "));
    if (sensors.length>1) {
      for (int i=0; i<numSensors; i++) {
        in[i] = sensors[i];
      }
    }
    print(in[0]*multiplier);
    print('\t');
    print(in[1]);
    print('\t');
    print(in[2]);
    print('\t');
    print(in[3]);
    print('\t');
    println(in[4]);
    //delay(00);
  }
  catch(RuntimeException e) {    //if string is unavailable
    println("Error parsing:");
    e.printStackTrace();
  }
  myPort.write("r");
}