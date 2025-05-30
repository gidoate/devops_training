#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <Arduino.h>

class TrafficLight {
public:
    TrafficLight(int rPin, int yPin, int gPin);
    void setup();
    void run(int delayTime); // no argument
private:
    int redPin, yellowPin, greenPin;
    int state = 0;
};
#endif // TRAFFIC_LIGHT_H
