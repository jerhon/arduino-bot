#include "SG90Servo.h"

SG90Servo::SG90Servo(int servoPin) {
    _servo.attach(servoPin);
}

void SG90Servo::setPosition(int angle) {
    _servo.write(angle);
}