const int aPin = 6;
const int bPin = 7;

int x = 0;

void setup()
{
  pinMode(aPin, INPUT_PULLUP);  
  pinMode(bPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  int change = getEncoderTurn();
  if (change != 0)
  {
    x += change;
    Serial.println(x);
  }
}

int getEncoderTurn()
{
  // return -1, 0, or +1
  static int oldA = 0;
  static int oldB = 0;
  int result = 0;
  int newA = digitalRead(aPin);
  int newB = digitalRead(bPin);
  if (newA != oldA || newB != oldB)
  {
    // something has changed
    if (oldA == 0 && newA == 1)
    {
      result = (oldB * 2 - 1);
    }
    else if (oldB == 0 && newB == 1)
    {
      result = -(oldA * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
} 
