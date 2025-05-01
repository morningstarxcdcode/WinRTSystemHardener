from typing import Dict

# Author: morningstarxcd

# MITRE ATT&CK Technique Mapping
MITRE_ATTACK_MAP: Dict[str, str] = {
    "powershell": "T1059 - Command and Scripting Interpreter",
    "mimikatz": "T1003 - Credential Dumping",
    "ping": "T1046 - Network Service Scanning",
    "whoami": "T1033 - System Owner/User Discovery"
}

def map_log_to_mitre(log_entry: str) -> str:
    """
    Map a log entry to a MITRE ATT&CK technique based on keywords.
    """
    log_entry_lower = log_entry.lower()
    for keyword, technique in MITRE_ATTACK_MAP.items():
        if keyword in log_entry_lower:
            return technique
    return "Unknown"

def test_map_log_to_mitre():
    """
    Test the map_log_to_mitre function with sample log entries.
    """
    test_logs = [
        "Detected use of powershell",
        "Unauthorized access using mimikatz",
        "Ping command executed for network scanning",
        "User executed whoami command",
        "No suspicious activity detected"
    ]

    for log in test_logs:
        mapped = map_log_to_mitre(log)
        print(f"Log: {log}\nMapped to MITRE: {mapped}\n")

if __name__ == "__main__":
    test_map_log_to_mitre()
