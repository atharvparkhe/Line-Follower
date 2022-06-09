void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
//  pinMode(10, OUTPUT);
}

void loop() {
//  digitalWrite(10, 65);
  int s0 = digitalRead(A0);
  int s1 = digitalRead(A1);
  int s2 = digitalRead(A2);
  int s3 = digitalRead(A3);
  int s4 = digitalRead(A4);
  String x = "\t";
  Serial.println(s0 + x + s1 + x + s2 + x + s3 + x + s4);
//Serial.println(s0);
  delay(100);
}
