#include "gtest/gtest.h"
#include "monitor.h"

// Test all edge cases
TEST(Monitor, VitalsOutOfRange) {
    ASSERT_FALSE(vitalsOk(103, 70, 95)); // temp high
    ASSERT_FALSE(vitalsOk(94, 70, 95));  // temp low
    ASSERT_FALSE(vitalsOk(98, 101, 95)); // pulse high
    ASSERT_FALSE(vitalsOk(98, 50, 95));  // pulse low
    ASSERT_FALSE(vitalsOk(98, 80, 85));  // spo2 low
    ASSERT_TRUE(vitalsOk(98.6, 75, 97)); // all normal
}
