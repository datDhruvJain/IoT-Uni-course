//Publishing DHT data to database
#include<DHT.h>
#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
DHT dht(D1,DHT11);
float hum,temp_c,temp_f;
char* ssid = "IoT_Lab";
char* pass = "iotlab123";
HTTPClient http;
WiFiClient client;
void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Connecting to WiFi..");
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
  Serial.println("WiFi Connected");
}
void loop() {
  hum = dht.readHumidity();
  temp_c = dht.readTemperature();
  temp_f = dht.readTemperature(true);
  Serial.print("Humidity:");Serial.print(hum);Serial.print(",");
  Serial.print("Temperature:");Serial.print(temp_c);Serial.print("*C,");
  Serial.print(temp_f);Serial.println("*F");
 
  String api = "http://15.206.203.246/?t=33&h="+String(hum)+"&t="+String(temp_c);
  http.begin(client, api);
  int code = http.GET();
  String response = http.getString();
  Serial.print("Status Code: ");Serial.println(code);
  Serial.println(response);
  delay(5000);
}
