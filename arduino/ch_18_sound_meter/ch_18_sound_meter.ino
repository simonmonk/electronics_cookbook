const int soundPin = A0;
const long samplePeriod = 100; // ms

long lastSampleTime = 0;
int maxAmplitude = 0;
int n = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long now = millis();
  if (now > lastSampleTime + samplePeriod) {
    processSoundLevel();
    n = 0;
    maxAmplitude = 0;
    lastSampleTime = now;
  }
  else {
    int amplitude = analogRead(soundPin) - 512;
    if (amplitude > maxAmplitude) {
      maxAmplitude = amplitude;
    }
    n++;
  }
}

void processSoundLevel() {
  // replace or add your own code to use maxAmplitude
  Serial.print("Of ");
  Serial.print(n);
  Serial.print(" samples, the maximum was ");
  Serial.println(maxAmplitude);
}

