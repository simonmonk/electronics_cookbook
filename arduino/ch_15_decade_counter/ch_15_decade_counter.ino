const int resetPin = 6;
const int clockPin = 7;

void setup() {
  pinMode(resetPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter digit 0..9");
}

void loop() {
  if (Serial.available()) {
    int digit = Serial.parseInt();
    setDigit(digit);
  }
}

void setDigit(int digit) {
  digitalWrite(resetPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(resetPin, LOW);
  for (int i = 0; i < digit; i++) {
    digitalWrite(clockPin, HIGH);
    delayMicroseconds(1);
    digitalWrite(clockPin, LOW);
    delayMicroseconds(1);
  }
}

