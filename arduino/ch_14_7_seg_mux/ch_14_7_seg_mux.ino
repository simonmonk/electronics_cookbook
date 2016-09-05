const int digitPins[] = {2, 3, 4, 5};
const int segPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

//                     abcdefgD
const char num[] = { 0b11111100,  // 0 abcdef
                     0b00001100,  // 1     ef
                     0b11011010,  // 2 ab de g
                     0b10011110,  // 3 a  defg
                     0b00101110,  // 4   c efg
                     0b10110110,  // 5 a cd fg
                     0b11110110,  // 6 abcd fg
                     0b00011100,  // 7    def
                     0b11111110,  // 8 abcdefg
                     0b10111110}; // 9 a cdefg

int digits[] = {1, 2, 3, 4};

void setup()
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(digitPins[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++)
  {
    pinMode(segPins[i], OUTPUT);
  }
}

void loop()
{
  refreshDisplay();
}

void refreshDisplay()
{
  for (int d = 0; d < 4; d++)
  {
    for (int seg=0; seg < 8; seg++)
    {
      digitalWrite(segPins[seg], LOW);
    }
    digitalWrite(digitPins[d], HIGH);
    for (int seg=0; seg < 8; seg++)
    {
      digitalWrite(segPins[seg], bitRead(num[digits[d]], 7-seg));
    }
    delay(1);
    digitalWrite(digitPins[d], LOW);
  }
}

