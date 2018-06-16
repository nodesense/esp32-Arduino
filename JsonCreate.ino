#include <ArduinoJson.h>

void setup() {
 Serial.begin(115200);
}

void loop() {
  DynamicJsonBuffer  jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["day"]= "Wednesday";
  int temp= 19;
  int humidity= 49;

  root["temperature"]= temp;
  root["Humidity"]= humidity;

  root.prettyPrintTo(Serial);
  Serial.println();

  while(1);

}
