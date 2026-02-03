#ifndef MOTORS_H
#define MOTORS_H

const int rightPin1 = 4;
const int rightPin2 = 3;
const int leftPin1 = 2;
const int leftPin2 = 1;

void moveForward();
void moveBack();
void turnLeft();
void turnRight();
void stopMotors();

#endif
