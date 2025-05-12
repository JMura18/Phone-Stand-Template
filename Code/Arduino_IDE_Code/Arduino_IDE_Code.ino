#include <Servo.h>

Servo myServo;

const int leftButtonPin = 11;
const int rightButtonPin = 12;
const int servoPin = 9;

int currentAngle = 90;      // Start at center
int targetAngle = 90;       // Desired angle

void setup() {
  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);
  myServo.attach(servoPin);
  myServo.write(currentAngle);
}

void loop() {
  bool leftPressed = digitalRead(leftButtonPin);
  bool rightPressed = digitalRead(rightButtonPin);

  if (leftPressed == LOW) {
    targetAngle = 0;  // move left
  } else if (rightPressed == LOW) {
    targetAngle = 180;  // move right
  } else {
    targetAngle = currentAngle;
  }

  // move left toward the target angle
  if (currentAngle < targetAngle) {
    currentAngle++;
    myServo.write(currentAngle);
    delay(10);  
  } else if (currentAngle > targetAngle) {
    currentAngle--;
    myServo.write(currentAngle);
    delay(10);
  }

  // If angles are equal, do nothing
}