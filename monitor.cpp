#include "monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

// Pure function: check if vitals are OK
bool vitalsOk(float temperature, float pulseRate, float spo2) {
    if (temperature < 95.0f || temperature > 102.0f) return false;
    if (pulseRate < 60.0f || pulseRate > 100.0f) return false;
    if (spo2 < 90.0f) return false;
    return true;
}

// I/O function: print blinking warning
void printVitalWarning(const char* message, int flashes) {
    std::cout << message << "\n";
    for (int i = 0; i < flashes; ++i) {
        std::cout << "\r* " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\r *" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
