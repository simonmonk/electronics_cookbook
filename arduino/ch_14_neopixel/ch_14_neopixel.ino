#include <Adafruit_NeoPixel.h>

const int pixelPin = 9;    
const int numPixels = 10;  

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  for (int i = 0; i < numPixels; i++) {
    int red = random(255);
    int green = random(255);
    int blue = random(255);
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
    pixels.show();
  }
  delay(100); 
}
