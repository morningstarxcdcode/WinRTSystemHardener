#include <iostream>
#include <fstream>
#include <string>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds

std::string analyze_threat_level(const std::string& log) {
    if (log.find("CVE") != std::string::npos) {
        return "High Threat Level: CVE Detected!";
    }
    if (log.find("unauthorized") != std::string::npos) {
        return "Medium Threat Level: Unauthorized Access!";
    }
    if (log.find("malicious") != std::string::npos) {
        return "Medium Threat Level: Malicious Activity Detected!";
    }
    return "Low Threat Level: No Immediate Threat.";
}

void monitor_logs() {
    std::ifstream logFile("dummy_logs.txt");
    if (!logFile.is_open()) {
        std::cerr << "Error: Could not open dummy_logs.txt. Make sure the file exists.\n";
        return;
    }

    std::string line;
    std::cout << "🔍 Starting Threat Level Analysis...\n";

    while (true) {
        while (getline(logFile, line)) {
            std::string threat = analyze_threat_level(line);
            std::cout << "Log: " << line << "\n" << "⚠️ " << threat << "\n\n";
        }
        logFile.clear(); // Clear EOF flag
        logFile.seekg(0); // Reset file pointer to the beginning
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Wait before re-scanning
    }
}

int main() {
    monitor_logs();
    return 0;
}
