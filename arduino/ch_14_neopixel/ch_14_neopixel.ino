#include <Adafruit_NeoPixel.h>  // 1

const int pixelPin = 9;    // 2
const int numPixels = 5;   // 3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, pixelPin, NEO_GRB + NEO_KHZ800); // 4

void setup() {
  pixels.begin(); // 5
}

void loop() {
  for (int i = 0; i < numPixels; i++) { // 6
    int red = random(255);
    int green = random(255);
    int blue = random(255);
    pixels.setPixelColor(i, pixels.Color(red, green, blue)); // 7
    pixels.show(); // 8
  }
  delay(100L); 
}
