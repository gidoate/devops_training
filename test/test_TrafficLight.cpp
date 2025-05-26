#include <ArduinoFake.h>
#include <gtest/gtest.h>
#include "TrafficLight.h"


TEST(TrafficLightTest, SetupPins) {
    TrafficLight tl(1, 2, 3);
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
    tl.setup();
    Verify(Method(ArduinoFake(), pinMode).Using(1, OUTPUT)).Once();
    Verify(Method(ArduinoFake(), pinMode).Using(2, OUTPUT)).Once();
    Verify(Method(ArduinoFake(), pinMode).Using(3, OUTPUT)).Once();
}

TEST(TrafficLightTest, RunSequence) {
    TrafficLight tl(10, 11, 12);

    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
    When(Method(ArduinoFake(), delay)).AlwaysReturn();

    tl.run(100);

    Verify(Method(ArduinoFake(), digitalWrite).Using(10, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(10, LOW)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(11, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(11, LOW)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(12, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(12, LOW)).Once();
    Verify(Method(ArduinoFake(), delay).Using(100)).Exactly(3);
}