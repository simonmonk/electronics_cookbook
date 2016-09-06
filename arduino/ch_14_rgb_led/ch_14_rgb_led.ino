const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  Serial.begin(9600);
  Serial.println("Enter R G B (E.g. 255 100 200)");
}

void loop() {
  if (Serial.available()) {
    int red = Serial.parseInt(); 
    int green = Serial.parseInt();
    int blue = Serial.parseInt();
    analogWrite(redPin, red); 
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
  }
}
    
