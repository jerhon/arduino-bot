#include "ObstacleAvoidanceCar.h"
#include "Arduino.h"

ObstacleAvoidanceCar::ObstacleAvoidanceCar(Car *car, SG90Servo *distanceServo, SR04DistanceSensor *distanceSensor) {
    _car = car;
    _distanceServo = distanceServo;
    _distanceSensor = distanceSensor;
}

void ObstacleAvoidanceCar::moveUntilObstruction(int avoidanceDistance) {
    
    unsigned int distance;

    // we are cautious, and it allows us better resolution on the sensor
    // motors don't seem to want to work under 100 load, so we'll use ~ half speed.
    _car->setSpeed(128);
    _car->moveForward();

    do {
        for (int i = 0; i <= 120; i+=15) {
            _distanceServo->setPosition(30 + i);
            delay(80);
            if (_distanceSensor->tryGetDistance(distance) && distance <= avoidanceDistance) {
                break;
            }
        }
    } while (distance == 0 || distance > avoidanceDistance);

    Serial.print(distance);
    Serial.println("<-- Distance");

    _car->stop();
}

bool ObstacleAvoidanceCar::findObstruction(unsigned int maxDistance, int startAngle, int endAngle, int increment, unsigned int &distance, int &angle) {

    // could have better algorithm
    distance = 10000;
    bool found = false;
    unsigned int lastDistance = 0;

    // find the obstruction with the SG90Servo
    for (int i = startAngle; i < endAngle; i+= increment) {
        _distanceServo->setPosition(i);
        delay(100); // requires a delay between readings?
        if (_distanceSensor->tryGetDistance(lastDistance) && lastDistance <= maxDistance) {
            if (lastDistance < distance) {
                angle = i;
                distance = lastDistance;
                found = true;
            }
        }
    }

    if (found) { 
        return true;
    } else {
        angle = 90;
        distance = 0;
        return false;
    }
}

void ObstacleAvoidanceCar::avoidObstruction() {

    
    _car->stop();

    unsigned int distance = 0;
    int angle = 90;

    // find the closest object within 50cm, and move away from it
    if (findObstruction(50, 0, 180, 20, distance, angle)) {

        // set the angle at which it was found for debug.
        _distanceServo->setPosition(angle);
        if (angle > 90) {
            _car->turnRight();
        } else {
            _car->turnLeft();
        }
        delay(750);
    }

    _car->stop();

}

void ObstacleAvoidanceCar::Drive() {
    _distanceServo->setPosition(90);
    moveUntilObstruction(30); //Avoid obstacles at a distance of 30cm
    avoidObstruction();
}