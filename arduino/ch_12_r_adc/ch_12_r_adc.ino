const int inputPin = A0;
const float r2 = 1000.0;
const float vin = 5.0;

void setup()
{
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(inputPin);
  float vout = reading / 204.6;
  float r1 = (r2 * (vin - vout)) / vout;
  Serial.print(r1); Serial.println(" Ohms");
  delay(500);
}

