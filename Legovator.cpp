#include "Legovator.h"
#include <Arduino.h>

Legovator::Legovator(Button *upButton, Button *downButton, MotorController *motor) {
    _motor = motor;
    _upButton = upButton;
    _downButton = downButton;
    _state = 0;
}

void Legovator::doStep() {

    int lastState = _state;
    if (_upButton->isPressed()) {
        _motor->forward();    
        _state = 1;
    } else if (_downButton->isPressed()) {
        _motor->backward();
        _state = 2;
    } else {
        _motor->stop();
        _state = 0;
    }

    // if the motor is starting, it needs a burst to get passed the stopping state,
    // but we only want to do that when we are changing from a stationary position to
    // movement.
    //
    // It may vary from motor to motor, and based on the load.

    if (lastState != _state && _state != 0) {
        _motor->speed(255);
        delay(333);

        if (_state == 1) {
            _motor->speed(150);
        } else  {
            _motor->speed(100);
        }
    }
}