
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLgXKxA3nL"
#define BLYNK_DEVICE_NAME "DhruvIOT"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

#include <DHT.h>

DHT dht(D3, DHT11);
double data;

void setup()
{
  Serial.begin(9600);
  pinMode(D1, OUTPUT);
  pinMode(D3, INPUT);
  delay(100);
  BlynkEdgent.begin();
  dht.begin();
}

BLYNK_WRITE(V0)
{
    int pinValue = param.asInt();
    digitalWrite(D1,pinValue);   
}


void loop() {
  BlynkEdgent.run();
  data = dht.readTemperature();
  Serial.println(data);
  Blynk.virtualWrite(V1, data);
  delay(2000);
}
