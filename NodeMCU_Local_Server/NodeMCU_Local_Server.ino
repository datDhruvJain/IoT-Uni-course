#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//char* ssid = "NodeMCU";
//char* pass ="12345678";
//char* ssid = "BITS-Students EG Lab";
//char* pass ="bitsstudents";

char* ssid = "IoT_Lab";
char* pass ="iotlab123";
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(D2,OUTPUT);
  Serial.println("Connecting to my Network...");
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
    delay(500);
    }
  Serial.println("WiFi is connected");
  server.begin();
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client){
  return;
  }
 Serial.println("Request receievd from the client");
 String request = client.readStringUntil('\r');
 Serial.println(request);

 if(request.indexOf("/on") != -1) {
    Serial.println("LED ON");
    digitalWrite(D2, HIGH);
  }

  if(request.indexOf("/off") != -1) {
    Serial.println("LED OFF");
    digitalWrite(D2, LOW);
  }

  client.println("<html><title>LED Control</title><center>");
  client.println("<h1>LED Control</h1>");
  client.println("<a href='/on'><button>Led ON</button></a>");
  client.println("<a href='/off'><button>Led OFF</button></a>");
  client.println("</center></html>");
}
