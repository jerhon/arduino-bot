#ifndef CAR_H
#define CAR_H

#include "MotorController.h"

/**
 * 
 *
 */
class Car
{
private:
    MotorController *_leftMotor, *_rightMotor;

public:
    Car(MotorController *leftMotor, MotorController *rightMotor);
    void moveForward();
    void moveBackward();
    void turnRight();
    void turnLeft();
    void setSpeed(int speed);
    void stop();
    void init();
};
#endif