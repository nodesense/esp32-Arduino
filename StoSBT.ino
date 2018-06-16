
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
char ch;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32est"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  //SerialBT.println("Hii");
  if (Serial.available()) {
    SerialBT.write(Serial.read());
   //SerialBT.println(Serial.read());
      
  }
  if (SerialBT.available()) {
    ch = SerialBT.read();
    Serial.write(ch);
    SerialBT.write(ch);
 
                                                                                                             
  delay(50);
 
}
