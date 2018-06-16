#include "EEPROM.h"

int addr = 0;
int i=0;
                                                                                  //#define EEPROM_SIZE 64
void setup()
{
  Serial.begin(115200);
  EEPROM.begin(64);
                                                                                    //if (!EEPROM.begin(EEPROM_SIZE))
                                                                                         //{
                                                                                     //Serial.println("failed to initialise EEPROM"); delay(1000000);
                                                                                         //}
  Serial.println("value reading from Flash is..");
    Serial.print((EEPROM.read(i))); Serial.print(" ");
      Serial.println();   
  Serial.println("Value writing to flash is..");
}

void loop()
{
   int val = 57;                                       //int val = analogRead(10) / 4;  //int val = byte(random(10020));
    EEPROM.write(addr, val);
     Serial.print(val); Serial.print(" ");
   
    EEPROM.commit();
//   Serial.print(EEPROM_SIZE);
   while(1);
  delay(100);
}
