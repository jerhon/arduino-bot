#ifndef SG90SERVO_H
#define SG90SERVO_H

// Use the Arduino library, and create a wrapper around it
// Reference to this library can be found here: https://www.arduino.cc/en/Reference/Servo
#include <Servo.h>

/**
 * A facade around the arduino servo library
 */
class SG90Servo
{
private:
    Servo _servo;
public:
    SG90Servo(int servoPin);
    void setPosition(int angle);
   
};

#endif