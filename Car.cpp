#include "Car.h"

Car::Car(MotorController *leftMotor, MotorController *rightMotor)
{
  _leftMotor = leftMotor;
  _rightMotor = rightMotor;
}

void Car::init()
{
  _leftMotor->init();
  _rightMotor->init();
}

void Car::moveForward()
{
  _leftMotor->forward();
  _rightMotor->forward();
}

void Car::moveBackward()
{
  _leftMotor->backward();
  _rightMotor->backward();
}

void Car::turnLeft()
{
  _rightMotor->forward();
  _leftMotor->backward();
}

void Car::turnRight()
{
  _leftMotor->forward();
  _rightMotor->backward();
}

void Car::setSpeed(int speed)
{
  _leftMotor->speed(speed);
  _rightMotor->speed(speed);
}

void Car::stop()
{
  _leftMotor->stop();
  _rightMotor->stop();
}
