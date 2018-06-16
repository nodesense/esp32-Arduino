#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "55D55";
const char* password =  "D#767365";
 
void setup() {
 
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin 
  connectToNetwork();
}
 void connectToNetwork() {
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("connecting to WiFi..");
  }
 
  Serial.println("Connected to network");
 
}
 
void loop() {
 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;   
// http.begin("http://jsonplaceholder.typicode.com/posts");
   http.begin("http://192.168.2.11:3000/gkp");  //Specify destination for HTTP request
  // http.addHeader("Content-Type", "application/json");             //Specify content-type header
 
   int httpResponseCode = http.POST("{\"temp\": 100, \"id\": \"1234\"}");   //Send the actual POST request
 
   if(httpResponseCode>0){
 
    String response = http.getString();                       //Get the response to the request
 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
   }else{
 
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
 
   }
 
   http.end();  //Free resources
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(10000);  //Send a request every 10 seconds
 
}
