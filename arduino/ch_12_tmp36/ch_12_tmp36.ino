const int inputPin = A0;

const float sensitivity = 0.01; // V/deg C
const float offset = -50.0;       // deg C

void setup()
{
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(inputPin);
  float volts = reading / 204.6;
  float degC = (volts / sensitivity) + offset;
  // float degF = degC * 9.0 / 5.0 + 32.0;
  Serial.println(degC);
  delay(500);
}

