#include <SimpleDHT.h>

const int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte temp;
  byte humidity;
  dht11.read(pinDHT11, &temp, &humidity, NULL);
  
  Serial.print(temp); Serial.print(" C, "); 
  Serial.print(humidity); Serial.println(" %");
  
  delay(1000);
}
