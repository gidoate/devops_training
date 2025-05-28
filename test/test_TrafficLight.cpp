#include <Arduino.h>
#include <unity.h>
#include "unity_config.h"

#include <config.h>
#include <TrafficLight.h>

TrafficLight trafficLight(RED_PIN, YELLOW_PIN, GREEN_PIN);

bool redState = false, yellowState = false, greenState = false;

void digitalWriteMock(int pin, int state) {
    if (pin == RED_PIN) redState = (state == HIGH);
    if (pin == YELLOW_PIN) yellowState = (state == HIGH);
    if (pin == GREEN_PIN) greenState = (state == HIGH);
}

void test_red_light() {
    trafficLight.run(DELAY_TIME);
    TEST_ASSERT_TRUE(redState);
}

void test_yellow_light() {
    trafficLight.run(DELAY_TIME);
    TEST_ASSERT_TRUE(yellowState);
}

void test_green_light() {
    trafficLight.run(DELAY_TIME);
    TEST_ASSERT_TRUE(greenState);
}

void setUp() {
    // Setup code if needed
}

void tearDown() {
    // Cleanup code if needed
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_red_light);
    RUN_TEST(test_yellow_light);
    RUN_TEST(test_green_light);
    UNITY_END();
}

void loop() {}
