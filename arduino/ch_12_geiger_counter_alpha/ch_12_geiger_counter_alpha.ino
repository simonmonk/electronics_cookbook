const unsigned int F = 32000;
const int OSC_PIN = 10;
const int INT_PIN = 2;
const int LED_PIN = 13;

volatile boolean blinkFlag = false;

void setup() {
  pinMode(OSC_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(INT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), event, RISING);
  tone(OSC_PIN, F);
}

void loop() {
  if (blinkFlag) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    blinkFlag = false;
  }
}

void event() {
  blinkFlag = true;
}

