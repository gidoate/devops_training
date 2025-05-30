#include "TrafficLight.h"
#include <Arduino.h>

TrafficLight::TrafficLight(int rPin, int yPin, int gPin)
    : redPin(rPin), yellowPin(yPin), greenPin(gPin), state(0) {}

void TrafficLight::setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    
    // Start with all LEDs off
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    
    state = 0;
}

void TrafficLight::run(int delayTime)
{
    switch (state) {
        case 0: // RED ON
            digitalWrite(redPin, HIGH);
            digitalWrite(yellowPin, LOW);
            digitalWrite(greenPin, LOW);

            Serial.print("State: RED=");
            Serial.print(digitalRead(redPin));
            Serial.print(" YELLOW=");
            Serial.print(digitalRead(yellowPin));
            Serial.print(" GREEN=");
            Serial.println(digitalRead(greenPin));

            delay(delayTime);
            digitalWrite(redPin, LOW);
            break;

        case 1: // YELLOW ON
            digitalWrite(redPin, LOW);
            digitalWrite(yellowPin, HIGH);
            digitalWrite(greenPin, LOW);

            Serial.print("State: RED=");
            Serial.print(digitalRead(redPin));
            Serial.print(" YELLOW=");
            Serial.print(digitalRead(yellowPin));
            Serial.print(" GREEN=");
            Serial.println(digitalRead(greenPin));

            delay(delayTime);
            digitalWrite(yellowPin, LOW);
            break;
            
        case 2: // GREEN ON
            digitalWrite(redPin, LOW);
            digitalWrite(yellowPin, LOW);
            digitalWrite(greenPin, HIGH);

            Serial.print("State: RED=");
            Serial.print(digitalRead(redPin));
            Serial.print(" YELLOW=");
            Serial.print(digitalRead(yellowPin));
            Serial.print(" GREEN=");
            Serial.println(digitalRead(greenPin));

            delay(delayTime);
            digitalWrite(greenPin, LOW);
            break;
    }
    state = (state + 1) % 3;
}