#include "TrafficLight.h"

TrafficLight::TrafficLight(int rPin, int yPin, int gPin)
    : redPin(rPin), yellowPin(yPin), greenPin(gPin) {}

void TrafficLight::setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void TrafficLight::run(int dTime)
{
    digitalWrite(redPin, HIGH);
    delay(dTime);
    digitalWrite(redPin, LOW);

    digitalWrite(yellowPin, HIGH);
    delay(dTime);
    digitalWrite(yellowPin, LOW);

    digitalWrite(greenPin, HIGH);
    delay(dTime);
    digitalWrite(greenPin, LOW);
}
