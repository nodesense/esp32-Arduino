#include <ArduinoJson.h>

void setup() {
   Serial.begin(115200);
  }

void loop() {
   StaticJsonBuffer<200> jsonBuffer;                                   // DynamicJsonBuffer  jsonBuffer(200);

   char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

    JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }

  // Fetch values.
  
  const char* sensor = root["sensor"];
  long time = root["time"];
  double latitude = root["data"][0];
  double longitude = root["data"][1];

  // Print values.
  Serial.println(sensor);
  Serial.println(time);
  Serial.println(latitude, 6);
  Serial.println(longitude, 6);
  while(1);

}
