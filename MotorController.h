#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

class MotorController
{
private:
    int _en, _in1, _in2;
    bool _init;

public:
    MotorController(int en, int in1, int in2);
    void init();
    void forward();
    void backward();
    void stop();
    void speed(int speed);
};

#endif