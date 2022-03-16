#include <DHT.h>

DHT dht(D1, DHT11);
float hum, temp_c, temp_f;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
    hum = dht.readHumidity();
    temp_c = dht.readTemperature();         
    Serial.print("humidity = ");Serial.print(hum);Serial.print(" ,  ");
    Serial.print("temperature = ");Serial.print(temp_c); Serial.println("C  ");
    delay(2000);
}
