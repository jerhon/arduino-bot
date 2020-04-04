#include <Arduino.h>
#include "Button.h"

Button::Button(int readPin) {
    _readPin = readPin;
}

void Button::setup() {
    pinMode(_readPin, INPUT);
}

bool Button::isPressed() {
    auto state = digitalRead(_readPin);
    return state == HIGH;
}

bool Button::isUp() {
    auto state = digitalRead(_readPin);
    return state == LOW;
}