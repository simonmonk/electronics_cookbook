const int ledPin = 13;

void setup() 
{
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);  // turn the LED on 
  delay(1000);                 // wait for a second
  digitalWrite(ledPin, LOW);   // turn the LED off 
  delay(1000);                 // wait for a second
}
