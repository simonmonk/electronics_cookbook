const int inputPin = 12;

void setup()
{
  pinMode(inputPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(inputPin) == false)
  {
    Serial.println("Button Pressed!");
    while (digitalRead(inputPin) == false) {};
    delay(10);
  }
}
