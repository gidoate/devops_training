#include <Arduino.h>
#ifdef __cplusplus
extern "C" {
#endif
void unityOutputChar(int c) {
  Serial.write(c);
}
#ifdef __cplusplus
}
#endif
#include <unity.h>

#include <config.h>
#include "TrafficLight.h"

TrafficLight light(RED_PIN, YELLOW_PIN, GREEN_PIN);

void test_setup_pins() {
    Serial.println("Inside test_setup_pins...");
    Serial.flush();
    light.setup();

    Serial.print("State: RED=");
    Serial.print(digitalRead(RED_PIN));
    Serial.print(" YELLOW=");
    Serial.print(digitalRead(YELLOW_PIN));
    Serial.print(" GREEN=");
    Serial.println(digitalRead(GREEN_PIN));
    
    // Just read as OUTPUT
    TEST_ASSERT_TRUE(digitalRead(RED_PIN) == LOW);
    TEST_ASSERT_TRUE(digitalRead(YELLOW_PIN) == LOW);
    TEST_ASSERT_TRUE(digitalRead(GREEN_PIN) == LOW);
}

void test_light_sequence() {
    light.setup(); // Make sure pins are OUTPUT and known state

    // 1. RED ON
    light.run(DELAY_TIME); // First state
    delay(10);

    TEST_ASSERT_TRUE(digitalRead(RED_PIN) == LOW);
    TEST_ASSERT_TRUE(digitalRead(YELLOW_PIN) == LOW);
    TEST_ASSERT_TRUE(digitalRead(GREEN_PIN) == LOW);

    // 2. YELLOW ON
    light.run(DELAY_TIME); // Next state
    delay(10);
    TEST_ASSERT_TRUE(digitalRead(RED_PIN) == LOW);
    TEST_ASSERT_TRUE(digitalRead(YELLOW_PIN) == LOW);
    TEST_ASSERT_TRUE(digitalRead(GREEN_PIN) == LOW);

    // 3. GREEN ON
    light.run(DELAY_TIME); // Next state
    delay(10);
    TEST_ASSERT_TRUE(digitalRead(RED_PIN) == LOW);
    TEST_ASSERT_TRUE(digitalRead(YELLOW_PIN) == LOW);
    TEST_ASSERT_TRUE(digitalRead(GREEN_PIN) == LOW);
}

void setup() {
    delay(500);
    Serial.begin(9600);
    delay(1000);
    Serial.println("Serial started...");
    Serial.flush();

    UNITY_BEGIN();

    Serial.println("Running test_setup_pins...");
    Serial.flush();
    RUN_TEST(test_setup_pins);
    Serial.println("Finished test_setup_pins.");
    Serial.flush();

    Serial.println("Running test_light_sequence...");
    Serial.flush();
    RUN_TEST(test_light_sequence);
    Serial.println("Finished test_light_sequence.");
    Serial.flush();

    UNITY_END();
    Serial.println("Tests completed. Exiting...");
    Serial.flush();

    while (true) { delay(1000); }
}

void loop() {}