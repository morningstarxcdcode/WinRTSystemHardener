// Author: morningstarxcd
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>

// Monitor logs for suspicious entries in real-time
void monitor_logs() {
    std::ifstream logFile("dummy_logs.txt");
    if (!logFile.is_open()) {
        std::cerr << "Error: Could not open dummy_logs.txt. Make sure the file exists.\n";
        return;
    }

    std::string line;
    std::cout << "🔍 Starting Real-Time Log Monitoring...\n";

    while (true) {
        while (getline(logFile, line)) {
            if (line.find("CVE") != std::string::npos ||
                line.find("unauthorized") != std::string::npos ||
                line.find("malicious") != std::string::npos) {
                std::cout << "⚠️ Suspicious log found: " << line << std::endl;
            }
        }
        logFile.clear();
        logFile.seekg(0);
        std::this_thread::sleep_for(std::chrono::seconds(5)); // wait before re-scanning
    }
}

// Test function for monitor_logs logic (simulated)
void test_log_monitor() {
    std::string test_logs[] = {
        "CVE-2024-1234 exploit detected",
        "Unauthorized access attempt",
        "Malicious activity logged",
        "Normal log entry"
    };

    for (const auto& log : test_logs) {
        if (log.find("CVE") != std::string::npos ||
            log.find("unauthorized") != std::string::npos ||
            log.find("malicious") != std::string::npos) {
            std::cout << "⚠️ Suspicious log found: " << log << std::endl;
        } else {
            std::cout << "Log is clean: " << log << std::endl;
        }
    }
}

int main() {
    // Run tests
    test_log_monitor();

    // Uncomment to run real-time monitoring
    // monitor_logs();

    return 0;
}
