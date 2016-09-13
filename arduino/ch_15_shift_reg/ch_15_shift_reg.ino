const int strobePin = 5;
const int dataPin = 6;
const int clockPin = 7;

void setup() {
  pinMode(strobePin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter Byte (in decimal)");
}

void loop() {
  if (Serial.available()) {
    char bits = Serial.parseInt();
    shiftOut(dataPin, clockPin, MSBFIRST, bits);
    digitalWrite(strobePin, HIGH);
    delayMicroseconds(10);
    digitalWrite(strobePin, LOW);
    Serial.println(bits, 2);
  }
}

