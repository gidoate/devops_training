#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <Arduino.h>

class TrafficLight
{
public:
    TrafficLight(int rPin, int yPin, int gPin);
    void setup();
    void run(int dTime);

private:
    const int redPin, yellowPin, greenPin;
};

#endif
