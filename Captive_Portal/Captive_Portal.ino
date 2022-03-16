#include<ESP8266WiFi.h>

char* ssid = "BITS-Students";
char* pass = "";
WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Connecting to Wifi...");
  WiFi.begin(ssid);
  while(WiFi.status()!=WL_CONNECTED){
      Serial.print(".");
      delay(500);
    }
    Serial.println("WiFi Connected");
}

void loop() {
  // put your main code here, to run repeatedly:
      delay(5000);
}
