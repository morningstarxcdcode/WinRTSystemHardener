// Author: morningstarxcd
#include <iostream>
#include <fstream>
#include <string>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds
#include <map>    // For std::map

// MITRE ATT&CK mapping for keywords
static const std::map<std::string, std::string> mitreMap = {
    {"powershell", "T1059 - Command and Scripting Interpreter"},
    {"mimikatz", "T1003 - Credential Dumping"},
    {"ping", "T1046 - Network Service Scanning"},
    {"whoami", "T1033 - System Owner/User Discovery"}
};

// Analyze threat level based on log content
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

// Map log entry to MITRE technique
std::string map_to_mitre(const std::string& log) {
    for (const auto& [keyword, technique] : mitreMap) {
        if (log.find(keyword) != std::string::npos)
            return technique;
    }
    return "Unknown Technique";
}

// Monitor logs and analyze threat levels in real-time
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
            std::string mitre = map_to_mitre(line);
            std::cout << "Log: " << line << "\n"
                      << "⚠️ Threat Level: " << threat << "\n"
                      << "MITRE Technique: " << mitre << "\n\n";
        }
        logFile.clear(); // Clear EOF flag
        logFile.seekg(0); // Reset file pointer to the beginning
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Wait before re-scanning
    }
}

// Test function for analyze_threat_level and map_to_mitre
void test_threat_level_analyzer() {
    std::string test_logs[] = {
        "Detected CVE-2024-1234 exploit",
        "Unauthorized login attempt",
        "Malicious script detected",
        "Normal operation log"
    };

    for (const auto& log : test_logs) {
        std::cout << "Log: " << log << "\n"
                  << "Threat Level: " << analyze_threat_level(log) << "\n"
                  << "MITRE Technique: " << map_to_mitre(log) << "\n\n";
    }
}

int main() {
    // Run tests
    test_threat_level_analyzer();

    // Uncomment to run real-time monitoring
    // monitor_logs();

    return 0;
}
