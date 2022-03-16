#include<ESP8266WiFi.h>
#include<Adafruit_MQTT.h>
#include<Adafruit_MQTT_Client.h>

#define ssid "IoT_Lab"
#define pass "iotlab123"
#define server "io.adafruit.com"
#define port 1883
#define user "dhruvjain"
#define key "aio_mcBm9858qaWyen0uy5lUXwp8wQoh"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client,server,port,user,key);
Adafruit_MQTT_Subscribe toggle = Adafruit_MQTT_Subscribe(&mqtt, user"/feeds/led");

void MQTT_Connect(){
     if(mqtt.connected()){
          return;
       }
     Serial.println("Connecting to MQTT...");
        int retries = 3,status;
     while((status = mqtt.connect()) != 0){
          Serial.println(mqtt.connectErrorString(status));
          Serial.println("Retrying after 5 secs....");
          delay(5000);
          retries--;
          if(retries == 0){
              while(1);   // reset the nodemcu
            }
      }
      Serial.println("MQTT Connected");
  }

void setup() {
    Serial.begin(9600);
    pinMode(D2,OUTPUT);
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid,pass);
    while(WiFi.status()!= WL_CONNECTED){
      Serial.print(".");
      delay(500);
    }
    Serial.println("WiFi Connected !");
    mqtt.subscribe(&toggle);
}

void loop() {
    MQTT_Connect();

    Adafruit_MQTT_Subscribe *subscription;
    while (subscription = mqtt.readSubscription(5000)){
       if (subscription == &toggle) {
        char* data = (char*)toggle.lastread;
          Serial.println(data);
           if(strcmp(data,"Hi")==0){
              digitalWrite(D2,HIGH);
              Serial.println("LED IS ON");
            }
           if(strcmp(data,"Bye")==0){
              digitalWrite(D2,LOW);
              Serial.println("LED IS OFF");
            }
       }

         
   }
}
