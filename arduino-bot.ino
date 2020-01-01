#include "Car.h"
#include "Pins.h"

Car *car;

void setup()
{
    // Setup the Car
    MotorController *rightMotor = new MotorController(MC_ENA, MC_IN1, MC_IN2);
    MotorController *leftMotor = new MotorController(MC_ENB, MC_IN3, MC_IN4);
    car = new Car(leftMotor, rightMotor);
    car->init();
    car->stop();

    // Setup Serial
    Serial.begin(9600);
}

void dance()
{
    // TODO: Add a method to make the robot do a little dance w/
    //
    // car->moveForward();
    // car->moveBackward();
    // car->turnLeft();
    // car->turnRight();
    // car->stop();
    // delay(milliseconds)
    car->setSpeed(100);

    for (int i = 0; i < 5; i++) {
        car->moveForward();
        delay(1000);
        car->turnLeft();
        delay(1000);
        car->moveBackward();
        delay(1000);
        car->turnRight();
        delay(1000);
    }
    car->stop();
}

void serialControl()
{
    if (Serial.available())
    {
        unsigned char direction = Serial.read();

        car->setSpeed(100);
        switch (direction)
        {
        case 'F':
            car->moveForward();
            break;
        case 'B':
            car->moveBackward();
            break;
        case 'L':
            car->turnLeft();
            break;
        case 'R':
            car->turnRight();
            break;
        case 'S':
            car->stop();
            break;
        case 'D':
            dance();
            break;
        }
    }
}

void loop()
{
    dance();
}
