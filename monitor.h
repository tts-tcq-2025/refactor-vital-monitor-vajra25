#pragma once

// Check if vitals are in range (pure function)
bool vitalsOk(float temperature, float pulseRate, float spo2);

// Print warning message with blinking animation (I/O function)
void printVitalWarning(const char* message, int flashes = 6);
