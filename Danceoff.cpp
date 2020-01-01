#include "Danceoff.h"

Danceoff::Danceoff(Car *car)
{
    _car = car;
}

// TODO: Add a method to make the robot do a little dance w/
//
// car->moveForward();
// car->moveBackward();
// car->turnLeft();
// car->turnRight();
// car->stop();
// delay(milliseconds)

void Danceoff::dance0()
{

    _car->setSpeed(100);

    for (int i = 0; i < 10; i++)
    {
        _car->moveForward();
        delay(500);
        _car->turnLeft();
        delay(500);
        _car->turnRight();
        delay(500);
        _car->turnLeft();
        delay(500);
    }

    _car->stop();
}

void Danceoff::dance1()
{
    _car->setSpeed(100);

    for (int i = 0; i < 20; i++)
    {
        _car->turnLeft();
        delay(250);
        _car->moveForward();
        delay(250);
    }

    _car->moveBackward();
    delay(2000);

    _car->moveForward();
    delay(2000);

    _car->turnRight();
    delay(2000);

    _car->turnLeft();
    delay(2000);

    _car->moveBackward();
    delay(2000);

    _car->stop();
}

void Danceoff::dance2()
{
    _car->setSpeed(100);

    _car->turnLeft();
    delay(5000);

    _car->moveForward();
    delay(500);

    _car->turnRight();
    delay(5000);

    _car->moveForward();
    delay(500);

    _car->moveBackward();
    delay(500);

    _car->turnLeft();
    delay(500);

    _car->moveBackward();
    delay(2500);

    _car->turnRight();
    delay(500);

    _car->moveForward();
    delay(500);

    _car->moveBackward();
    delay(500);

    _car->stop();
}

void Danceoff::dance3()
{

    _car->setSpeed(100);

    for (int i = 0; i < 10; i++)
    {
        _car->moveBackward();
        delay(250);

        _car->moveForward();
        delay(250);
    }

    for (int i = 0; i < 3; i++)
    {
        _car->turnLeft();
        delay(1000);

        _car->turnRight();
        delay(1000);
    }

    for (int i = 0; i < 10; i++)
    {
        _car->moveForward();
        delay(250);

        _car->turnLeft();
        delay(250);

        _car->moveBackward();
        delay(250);

        _car->turnRight();
        delay(250);
    }

    _car->stop();
}

int Danceoff::length()
{
    return 4;
}

void Danceoff::dance(int number)
{
    switch (number)
    {
    case 0:
        dance0();
        break;
    case 1:
        dance1();
        break;
    case 2:
        dance2();
        break;
    case 3:
        dance3();
        break;
    default:
        break;
    }
}