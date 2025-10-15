#pragma once

// Pure function: just checks vital signs, no printing or delays
bool vitalsOk(float temperature, float pulseRate, float spo2);

// Optional I/O function: prints warning with blinking animation
void printVitalWarning(const char* message, int flashes = 6);


