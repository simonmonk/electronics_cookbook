#include <Wire.h>
#include <TEA5767Radio.h>

TEA5767Radio radio = TEA5767Radio();

void setup() { 
  Serial.begin(9600);
  Serial.println("Enter Frequency:");
  Wire.begin();
}

void loop() {
  if (Serial.available()) {
    float f = Serial.parseFloat();
    radio.setFrequency(f);
    Serial.println(f);
  }
}
