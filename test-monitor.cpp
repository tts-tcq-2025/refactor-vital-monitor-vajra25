#include <gtest/gtest.h>
#include "./monitor.h"

// Test the pure function (no delays, no output)
TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
    // Temperature too high, pulse high, spo2 low
    ASSERT_FALSE(vitalsOk(103, 102, 70));

    // All vitals normal
    ASSERT_TRUE(vitalsOk(98.1, 70, 98));

    // Temperature too low
    ASSERT_FALSE(vitalsOk(94, 70, 95));

    // Pulse too low
    ASSERT_FALSE(vitalsOk(98, 50, 95));

    // Spo2 too low
    ASSERT_FALSE(vitalsOk(98, 80, 85));
}

