#include "monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

int vitalsOk(float temperature, float pulseRate, float spo2) {
    auto blink = []() {
        for (int i = 0; i < 6; ++i) {
            std::cout << "\r* " << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "\r *" << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    };

    if (temperature > 102.0f || temperature < 95.0f) {
        std::cout << "Temperature is critical!\n";
        blink();
        return 0;
    }
    if (pulseRate < 60.0f || pulseRate > 100.0f) {
        std::cout << "Pulse Rate is out of range!\n";
        blink();
        return 0;
    }
    if (spo2 < 90.0f) {
        std::cout << "Oxygen Saturation out of range!\n";
        blink();
        return 0;
    }
    return 1;
}
