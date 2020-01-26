#include "SR04DistanceSensor.h"

SR04DistanceSensor::SR04DistanceSensor(int triggerPin, int echoPin) {
    _distanceSensor = new NewPing(triggerPin, echoPin, 100);
}
SR04DistanceSensor::~SR04DistanceSensor() {
    delete _distanceSensor;
}

bool SR04DistanceSensor::tryGetDistance(unsigned int &distance, unsigned int maxDistance) {
    distance = _distanceSensor->ping_cm(maxDistance);
    return distance != 0;
}