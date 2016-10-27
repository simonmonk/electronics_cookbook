const int outputPin = 11;
const int sensePin = 2;

const int slotsPerRev = 20;
const long updatePeriod = 1000L; // ms

long lastUpdateTime = 0;
long pulseCount = 0;

float rpm = 0;

void setup()
{
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter speed 0 to 255");
  attachInterrupt(digitalPinToInterrupt(sensePin), incPulseCount, RISING);
}

void loop()
{
  if (Serial.available())
  {
    int setSpeed = Serial.parseInt();
    analogWrite(outputPin, setSpeed);
  }
  updateRPM();
}

void incPulseCount()
{
  pulseCount ++;
}

void updateRPM()
{
  long now = millis();
  if (now > lastUpdateTime + updatePeriod)
  {
    lastUpdateTime = now;
    rpm = float(pulseCount) * 60000.0 / (20.0 * updatePeriod);
    pulseCount = 0;
    Serial.println(rpm);
  }
}


