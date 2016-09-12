#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(4);

void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  display.drawRect(0, 0, display.width()-1, display.height()-1, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(5,10);
  display.print("Electronics Cookbook");
  display.display();
}

void loop() 
{ 
}
  
