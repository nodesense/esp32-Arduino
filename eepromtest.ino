#include "EEPROM.h"

int addr = 0;
int i=0;
int h;
                                                                                  //#define EEPROM_SIZE 64
void setup()
{
  Serial.begin(115200);
  EEPROM.begin(64);
}

void loop()
{
            int val = 25;                              //int val = analogRead(10) / 4;  //int val = byte(random(10020));
    while(1)
    {  
    Serial.println("Value writing to flash is.."); 
    EEPROM.write(addr, val);
     Serial.print(val); //Serial.print(" ");
     Serial.println();
     val++;
     delay(4000);
    Serial.println("value reading from Flash is..");
    //Serial.print(EEPROM.read(i)); //Serial.print(" ");
    h=EEPROM.read(i);
    Serial.print(h);  
   Serial.println(); 
    delay(4000);
      
    EEPROM.commit();
//   Serial.print(EEPROM_SIZE);
   //while(1);
  delay(100);
    }
}
