const int trigPin = 9;
const int echoPin = 10;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  float cm = takeSounding();
  Serial.print(int(cm));
  Serial.print(" cm ");
  int inches = int(cm / 2.5);
  Serial.print(inches);
  Serial.println(" inches");
  delay(500);
}


float takeSounding()
{
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); // 10us trigger pulse
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(200); // ingore echos while sending 200us
  long duration = pulseIn(echoPin, HIGH, 100000) + 200; 
  float distance = duration / 29.0 / 2.0;
  return distance;
}
