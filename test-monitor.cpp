#include "gtest/gtest.h"
#include "monitor.h"

TEST(Monitor, VitalsOutOfRange) {
    ASSERT_FALSE(vitalsOk(103.0f, 70.0f, 95.0f)); // high temp
    ASSERT_FALSE(vitalsOk(94.0f, 70.0f, 95.0f));  // low temp
    ASSERT_FALSE(vitalsOk(98.0f, 101.0f, 95.0f)); // high pulse
    ASSERT_FALSE(vitalsOk(98.0f, 50.0f, 95.0f));  // low pulse
    ASSERT_FALSE(vitalsOk(98.0f, 80.0f, 85.0f));  // low spo2
    ASSERT_TRUE(vitalsOk(98.6f, 75.0f, 97.0f));   // all normal
}
