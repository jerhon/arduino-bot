#ifndef SR04DISTANCESENSOR_H
#define SR04DISTANCESENSOR_H

#include <NewPing.h>

class SR04DistanceSensor {

private:
    NewPing *_distanceSensor;

public: 
    SR04DistanceSensor(int triggerPin, int echoPin);
    ~SR04DistanceSensor();
    bool tryGetDistance(unsigned int &distance, unsigned int maxDistance = 0U);

};

#endif