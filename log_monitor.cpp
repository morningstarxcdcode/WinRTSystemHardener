#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>

void monitor_logs() {
    std::ifstream logFile("dummy_logs.txt");
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

int main() {
    monitor_logs();
    return 0;
}
