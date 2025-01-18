/*
Тест билд клиента, то что делать нельзя вы уже знаете 
*/
 
#include <WiFi.h>
#include <PubSubClient.h>
#include <state_machine.h>
 
/* change it with your ssid-password */
const char* ssid = "ssid";
const char* password = "password";
/* this is the IP of PC/raspberry where you installed MQTT Server 
on Wins use "ipconfig" 
on Linux use "ifconfig" to get its IP address */
const char* mqtt_server = "192.168.4.1";

/* create an instance of PubSubClient client */
WiFiClient espClient;
PubSubClient client(espClient);

/* topics */
#define MQTT_STATE_TOPIC = "user_8202830b/state"
#define MQTT_FROM_CASE_TOPIC = "user_8202830b/frome_case"
#define MQTT_TO_CASE_TOPIC = "user_8202830b/to_case"
 
long lastMsg = 0;
char msg[20];
 
void receivedCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Command received: ");
  //Serial.println(topic);
 
  Serial.print("payload: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  /* we got '1' -> on */
  if ((char)payload[0] == '1') {
    service_mode_state();
  } 
  else if((char)payload[0] == '0'){
    /* we got '0' -> on */
    cooking_state();
  }
  else if((char)payload[[0]+(char)payload[[0]+(char)payload[[0]
 
}
 
void mqttconnect() {
  /* Loop until reconnected */
  while (!client.connected()) {
    Serial.print("MQTT connecting ...");
    /* client ID */
    String clientId = "ESP32Client";
    /* connect now */
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      /* subscribe topic with default QoS 0*/
      client.subscribe("#");
    } else {
      Serial.print("failed, status code =");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      /* Wait 5 seconds before retrying */
      delay(5000);
    }
  }
}
 
void setup() {
  Serial.begin(115200);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  /* set led as output to control led on-off */
  //pinMode(led, OUTPUT);
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  /* configure the MQTT server with IPaddress and port */
  client.setServer(mqtt_server, 1883);
  /* this receivedCallback function will be invoked 
  when client received subscribed topic */
  
  client.setCallback(receivedCallback);
  /*start DHT sensor */
  //dht.begin();

  setap_state();
}
void loop() {
  /* if client was disconnected then try to reconnect again */
  if (!client.connected()) {
    mqttconnect();
  }
  /* this function will listen for incomming 
  subscribed topic-process-invoke receivedCallback */
  client.loop();
}
