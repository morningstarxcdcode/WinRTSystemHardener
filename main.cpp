#include <iostream>
#include "include/hardener.hpp"

// Entry point for WinRT System Hardener application
int main() {
    std::cout << "🚀 WinRT System Hardener Started" << std::endl;

    // Start system reconnaissance
    startRecon();

    // Apply system hardening policies
    applyHardening();

    // Additional monitoring and threat blocking (future extension)
    // monitorApps();
    // blockThreats();

    std::cout << "✅ WinRT System Hardener Completed Successfully" << std::endl;

    return 0;
}
