#include <OneWire.h>
#include <DallasTemperature.h>

const int tempPin = 2;  

OneWire oneWire(tempPin);
DallasTemperature sensors(&oneWire);

void setup() 
{  
  Serial.begin(9600);
  sensors.begin();    
}

void loop() { 
  sensors.requestTemperatures(); 
  float temp = sensors.getTempCByIndex(0);  
  Serial.println(temp);
}

