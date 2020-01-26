
#include "Pins.h"
#include "Car.h"
#include "Danceoff.h"
#include "SG90Servo.h"
#include "SR04DistanceSensor.h"
#include "ObstracleAvoidanceCar.h"

Car *car;
Danceoff *tinyDancer;
SG90Servo *distanceServo;
SR04DistanceSensor *distanceSensor;
ObstacleAvoidanceCar *traveller;

void setup()
{
    // Setup the Car
    MotorController *rightMotor = new MotorController(MC_ENA, MC_IN1, MC_IN2);
    MotorController *leftMotor = new MotorController(MC_ENB, MC_IN3, MC_IN4);
    car = new Car(leftMotor, rightMotor);
    car->init();
    car->stop();

    distanceServo = new SG90Servo(SV_ANGLE);
    distanceSensor = new SR04DistanceSensor(US_TRIG, US_ECHO);

    tinyDancer = new Danceoff(car);
    traveller = new ObstacleAvoidanceCar(car, distanceServo, distanceSensor);

    // I have a bluetooth card which is wired to send data over the serial port.
    Serial.begin(9600);
    Serial.println("Starting Traveller.");
}

void allDances()
{
    for (int i = 0; i < tinyDancer->length(); i++)
    {
        tinyDancer->dance(i);
    }
}

void serialControl()
{
    if (Serial.available())
    {
        unsigned char command = Serial.read();
        car->setSpeed(100);
        switch (command)
        {
        case 'F':
            car->moveForward();
            delay(1000);
            car->stop();

            break;
        case 'B':
            car->moveBackward();
            delay(1000);
            car->stop();

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

        // TODO: store this in some sort of dictionary, and get rid of the switch
        case '0':
            tinyDancer->dance0();
            break;
        case '1':
            tinyDancer->dance1();
            break;
        case '2':
            tinyDancer->dance2();
            break;
        case '3':
            tinyDancer->dance3();
            break;
        case '4':
            allDances();
            break;
        }
    }
}

bool start = true;

void loop()
{
    traveller->Drive();
}