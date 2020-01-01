
#include "Pins.h"
#include "Car.h"
#include "Danceoff.h"

Car *car;
Danceoff *tinyDancer;

void setup()
{
    // Setup the Car
    MotorController *rightMotor = new MotorController(MC_ENA, MC_IN1, MC_IN2);
    MotorController *leftMotor = new MotorController(MC_ENB, MC_IN3, MC_IN4);
    car = new Car(leftMotor, rightMotor);
    car->init();
    car->stop();

    tinyDancer = new Danceoff(car);

    // Setup Serial
    Serial.begin(9600);
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
            //dance();
            break;
        }
    }
}

void loop()
{
    tinyDancer->dance0();

    while (true) {
        delay(500);
    }
}
