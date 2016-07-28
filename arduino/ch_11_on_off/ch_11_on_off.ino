const int outputPin = 11;

void setup()
{
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter 0 for off and 1 for on");
}

void loop()
{
  if (Serial.available())
  {
    char onOff = Serial.read();
    if (onOff == '1')
    {
      digitalWrite(outputPin, HIGH);
      Serial.println("Output ON.");
    }
    else if (onOff == '0')
    {
      digitalWrite(outputPin, LOW);
      Serial.println("Output OFF.");
    }
  }
}

