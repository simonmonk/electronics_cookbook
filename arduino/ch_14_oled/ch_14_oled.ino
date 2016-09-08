#include <OneWire.h>
#include <DallasTemperature.h>
#include <PID_v1.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const double minTemp = 0.0;  
const double maxTemp = 20.0;

double kp = 1500;     
double ki = 50.0;
double kd = 0.0;

const int tempPin = 2;
const int coolPin = 9;    
const int potPin = A0;
const long period = 1000; // >750

OneWire oneWire(tempPin);
DallasTemperature sensors(&oneWire);
Adafruit_SSD1306 display(4);

double setTemp = 0.0;
double measuredTemp = 0.0;
double outputPower = 0.0;     
long lastSampleTime = 0;

PID myPID(&measuredTemp, &outputPower, &setTemp, kp, ki, kd, REVERSE); 

void setup() {
  pinMode(coolPin, OUTPUT);
  Serial.begin(9600);
  sensors.begin();
  myPID.SetSampleTime(1000); // (4)
  myPID.SetMode(AUTOMATIC);  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}

void loop() { 
  long now = millis();         
  if (now > lastSampleTime + period) {
      checkTemperature();
      lastSampleTime = now;
  }
  setTemp = readSetTempFromPot(); 
}

void checkTemperature() {      
  measuredTemp = readTemp();  
  Serial.print(measuredTemp);
  Serial.print(", ");
  Serial.print(setTemp);
  Serial.print(", ");
  Serial.println(outputPower);
  myPID.Compute();
  analogWrite(coolPin, outputPower);
  updateDisplay();
}

double readSetTempFromPot() {   
  static double oldTemp = 0;
  int raw = analogRead(potPin);
  double temp = map(raw, 0, 1023, minTemp, maxTemp);
  if (oldTemp != temp) {
    updateDisplay();
    oldTemp = temp;
  }
  return temp;
} 

double readTemp() {
  sensors.requestTemperatures(); 
  return sensors.getTempCByIndex(0);  
}

void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Temp:");
  display.println(measuredTemp);
  display.print("Set: ");
  display.println(setTemp);
  display.display();
}
  
