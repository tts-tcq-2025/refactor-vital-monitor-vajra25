#include "./monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::seconds;

// Pure function: just checks the vital ranges
bool vitalsOk(float temperature, float pulseRate, float spo2) {
    if (temperature > 102 || temperature < 95) return false;
    if (pulseRate < 60 || pulseRate > 100) return false;
    if (spo2 < 90) return false;
    return true;
}

// I/O function: blinking warning
void printVitalWarning(const char* message, int flashes) {
    cout << message << "\n";
    for (int i = 0; i < flashes; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}
