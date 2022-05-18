#include<DHT.h>
#include<ESP8266WiFi.h>
#include<ThingSpeak.h>

DHT dht(D1, DHT11);
float hum, temp_c, temp_f;
int led_status = 0;
char* ssid = "IoT_Lab";
char* pass = "iotlab123";
WiFiClient client;
long id = 1651944;
char* api = "7TYCS113YX0I1BKM";
void setup() {
  // put your setup code here, to run once:
  pinMode(D2, OUTPUT);  // For humidity alarm
  pinMode(D3, OUTPUT);  // For temprature alarm
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
      

      if (temp_c > 25){
        digitalWrite(D2, HIGH);
        led_status = 1;
      }

      else {
        digitalWrite(D2, LOW);
        led_status = 0;
      }
      
      ThingSpeak.setField(1, hum);
      ThingSpeak.setField(2, temp_c);
      ThingSpeak.setField(3, led_status);
      ThingSpeak.writeFields(id, api);

      delay(5000);
}
