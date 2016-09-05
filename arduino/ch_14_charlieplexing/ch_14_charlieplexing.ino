
const int pins[] = {5, 6, 7};

const int pinLEDstates[6][3] = {
  {1, 0, -1}, // LED 1
  {0, 1, -1}, // LED 2
  {-1, 1, 0}, // LED 3
  {-1, 0, 1}, // LED 4
  {1, -1, 0}, // LED 5
  {0, -1, 1}  // LED 6
};

int ledState[6];

void setup()
{
  Serial.begin(9600);
  Serial.println("LED Number (0 to 5)");
}

void loop()
{
  if (Serial.available())
  {
    int led = Serial.parseInt();
    ledState[led] = ! ledState[led];
  }
  refresh();
}



void refresh()
{
  for (int led = 0; led < 6; led ++)
  {
    clearPins();
    if (ledState[led])
    {
      setPins(led);
    }
    else
    {
      clearPins();
    }
    delay(1);
  }
}

void setPins(int led)
{
  for (int pin = 0; pin < 3; pin ++)
  {
    if (pinLEDstates[led][pin] == -1)
    {
      pinMode(pins[pin], INPUT);
    }
    else
    {
      pinMode(pins[pin], OUTPUT);
      digitalWrite(pins[pin], pinLEDstates[led][pin]);
    }
  }
}

void clearPins()
{
  for (int pin = 0; pin < 3; pin ++)
  {
      pinMode(pins[pin], INPUT);
  }
}

