
// TRY THIS

const int motor1SpeedPin = 5;
const int motor2SpeedPin = 6;

const int motor1DirAPin = 2;
const int motor1DirBPin = 3;
const int motor2DirAPin = 4;
const int motor2DirBPin = 7;

void setup()
{
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
  pinMode(motor1DirAPin, OUTPUT);
  pinMode(motor1DirBPin, OUTPUT);
  pinMode(motor2DirAPin, OUTPUT);
  pinMode(motor2DirBPin, OUTPUT);
  Serial.begin(9600);
  // M1 full speed clockwise
  analogWrite(motor1SpeedPin, 255);
  digitalWrite(motor1DirAPin, LOW); 
  digitalWrite(motor1DirBPin, HIGH);
  // M2 half speed counter-clockwise
  analogWrite(motor2SpeedPin, 127);
  digitalWrite(motor2DirAPin, HIGH); 
  digitalWrite(motor2DirBPin, LOW);
}

void loop()
{
}

