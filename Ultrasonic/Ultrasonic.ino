// defines variables
long duration;
int distance;

void setup() {
pinMode(D4, OUTPUT); // Sets the trigPin as an Output
pinMode(D1, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {

// Clears the trigPin
digitalWrite(D4, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(D4, HIGH);
delayMicroseconds(10);
digitalWrite(D4, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(D1, HIGH);

// Calculating the distance
distance= duration/74/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(2000);
}
