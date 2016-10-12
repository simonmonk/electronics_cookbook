const int outputPin = 10;

void setup()
{
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter frequency 100-8000 Hz (0 off)");
}

void loop()
{
  if (Serial.available())
  {
    long f = Serial.parseInt();
    if (f == 0) {
      noTone(outputPin);
    }
    else {
      tone(outputPin, f);
    }
  }
}

