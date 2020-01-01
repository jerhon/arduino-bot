#include "Danceoff.h"

Danceoff::Danceoff(Car* car) {
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

void Danceoff::dance0() {
    
    _car->setSpeed(100);

    for (int i = 0; i < 10; i++) {
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


void Danceoff::dance1() {

    _car->setSpeed(100);
    

}