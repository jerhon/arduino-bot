#ifndef DANCEOFF_H
#define DANCEOFF_H

#include <Arduino.h>
#include "Car.h"

// TODO: split each dance into a seperate class

class Danceoff
{
    Car *_car;

public:
    Danceoff(Car *car);

    void dance0();
    void dance1();
    void dance2();
    void dance3();

    int length();
    void dance(int number);
};

#endif