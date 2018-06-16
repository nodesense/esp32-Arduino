#include <Arduino.h>
#include <U8g2lib.h>


//#ifdef U8X8_HAVE_HW_SPI
//#include <SPI.h>
//#endif
//#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
//#endif

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

void setup(void) {

  u8g2.begin();
}

void loop(void) {
 
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(0,10,"HELLO WORLD");
  u8g2.drawStr(0,20,"INDIA");	// write something to the internal memory
  u8g2.drawStr(0,30,"12345");
  u8g2.drawStr(0,40,"@#$%&");
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);  
 
}

