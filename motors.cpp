#include "motors.h"
#include <Arduino.h>

void moveForward() {
  digitalWrite(rightPin1, HIGH);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, HIGH);
  digitalWrite(leftPin2, LOW);
}

void moveBack() {
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, HIGH);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, HIGH);
}

void turnLeft() {
  digitalWrite(rightPin1, HIGH);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, LOW);
}

void turnRight() {
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, HIGH);
  digitalWrite(leftPin2, LOW);
}

void stopMotors() {
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, LOW);
}