//Билд тестовый, мозги не ебать ничего не трогат(всё на замёрших соплях, изоленте и жвачке)

#include <ESP8266WiFi.h>
#include "uMQTTBroker.h"
#include "confige.h"

uMQTTBroker myBroker;

void WifiClient()
{
  //Serial.println("Connection as client..");
  WiFi.begin(ssid, pass);
  
  //Serial.println("WiFi connected.");
  //Serial.println("IP: " + WiFi.localIP().toString());
}

void WiFiAP()
{
  WiFi.softAP(ssid, pass);
  //Serial.println("AP started");
  //Serial.println("IP address: " + WiFi.softAPIP().toString());
}


void setup() {
  if(wifiAP) WiFiAP();
  else WifiClient();

  //Serial.println("Starting MQTT broker");
  myBroker.init();
}

void loop() {
  // put your main code here, to run repeatedly:

}
