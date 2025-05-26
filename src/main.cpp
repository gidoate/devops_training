#include <Arduino.h>
#include <TrafficLight.h>
#include <config.h>

TrafficLight trafficLight(RED_PIN, YELLOW_PIN, GREEN_PIN);

void setup()
{
    Serial.begin(9600);
    trafficLight.setup();
}

void loop()
{
    trafficLight.run(DELAY_TIME);
}
