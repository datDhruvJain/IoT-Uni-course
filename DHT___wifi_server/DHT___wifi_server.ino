#include<DHT.h>
#include<ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include<ThingSpeak.h>


DHT dht(D1, DHT11);
float hum, temp_c, temp_f;
char* ssid = "IoT_Lab";
char* pass = "iotlab123";
WiFiServer server(80);
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
    server.begin();
    Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
    WiFiClient client = server.available();
    if (!client){
      return;
    }
    Serial.println("Request receievd from the client");
    String request = client.readStringUntil('\r');
    Serial.println(request);

    if(request.indexOf("/read") != -1) {
    Serial.println("Reading DHT");
    hum = dht.readHumidity();
      temp_c = dht.readTemperature();
      Serial.print("Humidity"); Serial.print(hum); Serial.print(" %");
      Serial.print("Temprature"); Serial.print(temp_c); Serial.print(" C\n");
      ThingSpeak.setField(1, hum);
      ThingSpeak.setField(2, temp_c);
      ThingSpeak.writeFields(id, api);

      delay(5000);
  }

  if(request.indexOf("/off") != -1) {
    Serial.println("DHT reading OFF");
  }

  client.println("<html><title>DHT Control</title><center>");
  client.println("<h1>DHT Control</h1>");
  client.println("<a href='/read'><button>DHT ON</button></a>");
  client.println("<a href='/off'><button>DHT OFF</button></a>");
  client.println("</center></html>");
      
}
