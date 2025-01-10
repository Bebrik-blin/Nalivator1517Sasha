//Внимание! Билд тестовый блядь, ничё не трогать! Всё на соплях!КОСТЯ НЕ БОМБИ, ЗДЕСЬ ВСЁ ХУЙНЯ И НЕ ОПТИМИЗИРОВАНО, Я ЗНАЮ!

//#include "ESP8266WiFi.h"
//#include "uMQTTBroker.h"
#include "confige.h"

char ssid[] = "ssid"; //id in network
char password = "12321"; //password from wifi



class MyMqtt
{
public:
  virtual void ClientConect(IPAddress addr, String client_id) {
      Serial.println(addr.toString()+" ("+client_id+") connected");
  }
  virtual void ClientDisconect(IPAddress addr, String client_id) {
      Serial.println(addr.toString()+" ("+client_id+") disconnected");
  }
}

myMqtt myBroker;


void startWiFiClient()
{
  Serial.println("Connecting to "+(String)ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  
  Serial.println("WiFi connected");
  Serial.println("IP address: " + WiFi.localIP().toString());
}


void startWiFiAP()
{
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, pass);
  Serial.println("AP started");
  Serial.println("IP address: " + WiFi.softAPIP().toString());
}

void setup() {
  if(wifiAP){startWIFIAP();}
  else{startWIFIClient();}

}

void loop() {
  // put your main code here, to run repeatedly:

}
