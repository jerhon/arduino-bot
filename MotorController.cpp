#include "MotorController.h"
#include <Arduino.h>

MotorController::MotorController(int en, int in1, int in2)
{
    _en = en;
    _in1 = in1;
    _in2 = in2;
    _init = false;
}

void MotorController::init()
{
    if (!_init)
    {
        pinMode(_in1, OUTPUT); // pin 7
        pinMode(_in2, OUTPUT); // pin 8
        pinMode(_en, OUTPUT);  // pin 11 (PWM)
        _init = true;
    }
}

void MotorController::forward()
{
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
}

void MotorController::backward()
{
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
}

void MotorController::stop()
{
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, HIGH);
}

void MotorController::speed(int speed)
{
    analogWrite(_en, speed);
}
