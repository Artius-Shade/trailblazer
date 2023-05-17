int eanMotorPin1 = 5;
int motor1pin1 = 6;
int motor1pin2 = 7;

int motor2pin1 = 8;
int motor2pin2 = 9;
int eanMotorPin2 = 10;

void setup() {
// put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(eanMotorPin1, OUTPUT);
  pinMode(eanMotorPin2, OUTPUT);
}

void loop() {
  // write the code here to run it in a loop:
}

void changeSpeed(int motor1Speed, int motor2Speed = 100001) {
  if (motor2Speed == 100001) motor2Speed = motor1Speed;
  analogWrite(eanMotorPin1, motor1Speed);
  analogWrite(eanMotorPin2, motor2Speed);
}

void fwd(int speed) {
  changeSpeed(speed);

  digitalWrite(motor1pin1, HIGH); 
  digitalWrite (motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite (motor2pin2, LOW);
}

void bwd(int speed) {
  changeSpeed(speed);

  digitalWrite (motor1pin2, LOW);
  digitalWrite(motor1pin1, HIGH); 

  digitalWrite (motor2pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
}

void turnLeft(int turnIntensity) {
  // TODO: Poor logic, needs improvement.
  changeSpeed(turnIntensity, 0);

  digitalWrite(motor1pin1, HIGH); 
  digitalWrite (motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite (motor2pin2, LOW);
}

void turnRight(int turnIntensity) {
  // TODO: Poor logic, needs improvement.
  changeSpeed(0, turnIntensity);

  digitalWrite(motor1pin1, HIGH); 
  digitalWrite (motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite (motor2pin2, LOW);
}

void spin(int speed) {
  changeSpeed(speed);

  digitalWrite(motor1pin1, HIGH); 
  digitalWrite (motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite (motor2pin2, HIGH);
}

void stop() {
  changeSpeed(0);
}