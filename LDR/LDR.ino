void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(D2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(A0);
  data /= 2;
  analogWrite(D2, data);
  Serial.println(data);
  delay(500);
}
