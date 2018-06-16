#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "55D55";
const char* password =  "D#767365";
const char* mqttServer = "192.168.2.4";
const int mqttPort = 1883;
//const char* mqttUser = "mqtt user id";
//const char* mqttPassword = "pasword";
 
WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

 
void setup() {

 

  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);

  client.setCallback(callback);
  
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP32Client")) {
 
      Serial.println("connected");
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }

  client.subscribe("esp/test");
  client.publish("esp/test", "Hello from ESP32");
 
}
 
void loop() {
  client.loop();
}

