#ifndef OBSTACLE_AVOIDANCE_H
#define OBSTACLE_AVOIDANCE_H

#include "Car.h"
#include "SG90Servo.h"
#include "SR04DistanceSensor.h"


class ObstacleAvoidanceCar {
private: 
    Car *_car; 
    SG90Servo *_distanceServo; 
    SR04DistanceSensor *_distanceSensor;

    int state;

    bool findObstruction(unsigned int maxDistance, int startAngle, int endAngle, int increment, unsigned int &distance, int &angle);
    void moveUntilObstruction(int avoidanceDistance);
    void avoidObstruction();

public: 
    ObstacleAvoidanceCar(Car *car, SG90Servo *distanceServo, SR04DistanceSensor *distanceSensor);

    /**
     * Drives forward move while looking for an obstruction.  When one is found, the car turns to avoid it.
     */
    void Drive();

    
};

#endif