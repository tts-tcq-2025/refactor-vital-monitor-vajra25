#include "gtest/gtest.h"
#include "monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
    ASSERT_FALSE(vitalsOk(103.0f, 70.0f, 95.0f)); // temp high
    ASSERT_FALSE(vitalsOk(94.0f, 70.0f, 95.0f));  // temp low
    ASSERT_FALSE(vitalsOk(98.0f, 101.0f, 95.0f)); // pulse high
    ASSERT_FALSE(vitalsOk(98.0f, 50.0f, 95.0f));  // pulse low
    ASSERT_FALSE(vitalsOk(98.0f, 80.0f, 85.0f));  // spo2 low
    ASSERT_TRUE(vitalsOk(98.6f, 75.0f, 97.0f));   // all normal
}
