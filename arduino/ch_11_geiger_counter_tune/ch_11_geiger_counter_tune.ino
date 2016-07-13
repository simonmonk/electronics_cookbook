unsigned int f = 30000;

int pin = 10;

void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  tone(pin, f);
}

void loop() {
  if (Serial.available())
  {
    f = Serial.parseFloat();
    Serial.println(f);
    tone(pin, f);
  }
}
