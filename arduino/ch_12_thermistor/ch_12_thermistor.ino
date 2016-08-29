const int inputPin = A0;

// r2 is the bottom fixed resistor in the voltage divider
const float r2 = 1000.0;

// thermistor properties
const float B = 3800.0;
const float r0 = 1000.0;

// other constants
const float vin = 5.0;
const float t0k = 273.15;
const float t0 = t0k + 25;

void setup()
{
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(inputPin);
  float vout = reading / 204.6;
  float r = (r2 * (vin - vout)) / vout;

  float inv_t = 1.0/t0 + (1.0/B) * log(r/r0);
  float t = (1.0 / inv_t) - t0k;
  
  Serial.print(t); Serial.println(" deg C");
  delay(500);
}
