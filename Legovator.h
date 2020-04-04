#ifndef LEGOVATOR_H
#define LEGOVATOR_H

#include "Button.h"
#include "MotorController.h"

class Legovator {

    private:
        int _state;
        Button *_upButton;
        Button *_downButton;
        MotorController *_motor;

    public:
        Legovator(Button *upButton, Button *downButton, MotorController *motor);

        void doStep();
};

#endif