const int inputPin = A0;

void setup()
{
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(inputPin);
  float volts = reading / 204.6;
  Serial.println(volts);
  delay(500);
}

