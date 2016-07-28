const int outputPin = 11;

void setup()
{
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter brightness 0 to 255");
}

void loop()
{
  if (Serial.available())
  {
    int brightness = Serial.parseInt();
    if (brightness >= 0 && brightness <= 255)
    {
      analogWrite(outputPin, brightness);
      Serial.println("Changed.");
    }
    else 
    {
      Serial.println("0 to 255");
    }
  }
}

