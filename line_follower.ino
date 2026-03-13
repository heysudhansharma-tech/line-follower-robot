int leftSensor = 2;
int rightSensor = 3;
int motor1Pin1 = 4;
int motor1Pin2 = 5;
int motor2Pin1 = 6;
int motor2Pin2 = 7;

void setup() {
  Serial.begin(9600);   // Serial Monitor चालू

  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  pinMode(9, OUTPUT);   // Enable pins
  pinMode(10, OUTPUT);
  digitalWrite(9, HIGH);   // Left motor enable
  digitalWrite(10, HIGH);  // Right motor enable
}

void loop() {
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  // Serial Monitor पर values दिखाएँ
  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print(" | Right: ");
  Serial.println(rightValue);

  if (leftValue == 1 && rightValue == 1) {
    forward();
  }
  else if (leftValue == 0 && rightValue == 1) {
    turnLeft();
  }
  else if (leftValue == 1 && rightValue == 0) {
    turnRight();
  }
}

void forward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}
