
// Motor Pins
#define m1 4  //Right Motor 1
#define m2 5  //Right Motor 2
#define m3 2  //Left Motor 1
#define m4 3  //Left Motor 2

// Motor Speed Control (enable) Pins
#define e1 9  //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB

// Sensor Pins
#define ir1 A4
#define ir2 A3
#define ir3 A2
#define ir4 A1
#define ir5 A0

// Light Pin and intensity
#define light 7

void setup() {

  Serial.begin(9600);
  
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  pinMode(light, OUTPUT);
}

void forward(int s){
  analogWrite(e1, s);
  analogWrite(e2, s);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void left(){
  analogWrite(e1, 255);
  analogWrite(e2, 255);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void slow_left(){
  analogWrite(e1, 255);
  analogWrite(e2, 255);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

void right(){
  analogWrite(e1, 255);
  analogWrite(e2, 255);
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void slow_right(){
  analogWrite(e1, 255);
  analogWrite(e2, 255);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void loop() {

  // Sensor Lights
//  digitalWrite(light, HIGH);

  int last;
  
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

/*
 * Possible conditions
 * 
 * 0 0 0 0 0
 * 1 1 1 1 1
 * 
 * 0 0 0 0 1
 * 1 0 0 0 0
 * 
 * 0 0 0 1 0
 * 0 1 0 0 0
 * 
 * 0 0 0 1 1
 * 1 1 0 0 0
 * 
 * 0 0 1 1 0
 * 0 1 1 0 0
 * 
 * 0 0 1 0 0
 * 
 * 0 1 1 1 0
 * 
 */

// testing
// left();
// right();
// slow_left();
// slow_right();
//  String x = "\t";
//  Serial.println(s1 + x + s2 + x + s3 + x + s4 + x + s5);
//  delay(100);

 
  //if only middle sensor(s) detects
  if( ((s1==1)&&(s2==1)&&(s3==0)&&(s4==1)&&(s5==1)) || ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)) )
  {
    forward(180);
  }

  //if left center sensor detects
  if( ((s1==1)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)) || ((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)) )
  {
    left();
  }

  //if left most sensor detects
  if( ((s1==0)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)) || ((s1==1)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1)) || ((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1)) )
  {
    slow_left();
  }

  //if right most sensor detect
  if(((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)) || ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==1)) || ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)) )
  {
    slow_right();
  }

  //if right most sensor detect
  if(((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==1)) || ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)))
  {
    right();
  }
  
  //if all sensor detects
  if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0))
  {
    forward(150);
  }

  //if no sensor detect
  if((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1))
  {
    slow_left();
  }
  
}
