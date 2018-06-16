#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "55D55";
const char* password =  "D#767365";
 
void setup() {
 
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi..");
 }
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    http.begin("http://192.168.2.11:3000/gkp"); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(10000);
 
}
