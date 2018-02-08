import processing.serial.*;

Serial myPort;
int numSensors = 2;
float[] sensors;
int x;
float[] in;
int[] axis;

void setup() {
  size(1000, 300); 
  background(0);
  frameRate(60);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[3], 9600);
  myPort.bufferUntil('\n');
  sensors = new float[numSensors];
  in = new float[numSensors];
  axis = new int[numSensors];
  axis[0] = height/2;
  axis[1] = height;
}
void draw() {
  //start of monitor
  stroke(0);
  line(x, 0, x, height);
  line(x+1, 0, x+1, height);
  stroke(0, 255, 0);
  line(x, axis[0], x, axis[0]-in[0]/10);
  line(x, axis[1], x, axis[1]-in[1]*50);
  x+=2;
  if (x > width) {
    x = 0;
  }  
  //end of monitor
  //saveFrame("k08_####.png");
}
void serialEvent(Serial myPort) {
  String myString; //definition of series of string from arduino            //if port 0 is available
  try {                             //if string is available
    myString = myPort.readStringUntil('\n');
    myString = trim(myString);
    sensors = float(split(myString, '\t'));
    if (sensors.length>1) {
      for (int i=0; i<numSensors; i++) {
        in[i] = sensors[i];
      }
    }
    print(in[0]);
    print('\t');
    println(in[1]);
  }
  catch(RuntimeException e) {    //if string is unavailable
    println("Error parsing:");
    e.printStackTrace();
  }
}