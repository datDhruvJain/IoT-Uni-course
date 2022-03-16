#include<DHT.h>
#include<ESP8266WiFi.h>
#include<ThingSpeak.h>

DHT dht(D1, DHT11);
float hum, temp_c, temp_f;
char* ssid = "IoT_Lab";
char* pass = "iotlab123";
WiFiClient client;
long id = 1651944;
char* api = "7TYCS113YX0I1BKM";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  Serial.println("Connecting to Wifi...");
  WiFi.begin(ssid, pass);
  while(WiFi.status()!=WL_CONNECTED){
      Serial.print(".");
      delay(500);
    }
    Serial.println("WiFi Connected");
    ThingSpeak.begin(client);

}

void loop() {
  // put your main code here, to run repeatedly:
      hum = dht.readHumidity();
      temp_c = dht.readTemperature();
      Serial.print("Humidity"); Serial.print(hum); Serial.print(" %");
      Serial.print("Temprature"); Serial.print(temp_c); Serial.print(" C\n");
      ThingSpeak.setField(1, hum);
      ThingSpeak.setField(2, temp_c);
      ThingSpeak.writeFields(id, api);

      delay(5000);
}
