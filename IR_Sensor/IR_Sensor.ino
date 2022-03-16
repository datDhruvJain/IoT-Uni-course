int val = 0;
void setup() {
  pinMode(D1, INPUT);
  pinMode(D2, OUTPUT);
}

void loop() {
  val = digitalRead(D1);
  if (val == LOW){
    digitalWrite(D2, HIGH);
   }

  else digitalWrite(D2, LOW);

}
