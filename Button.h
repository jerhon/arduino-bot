#ifndef BUTTON_H
#define BUTTON_H

class Button {

    int _readPin;

public:

    Button(int readPin);

    void setup();

    bool isPressed();
    bool isUp();


};

#endif