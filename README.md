
<<<<<<< HEAD
This project enhances Windows runtime security by leveraging the power of **CsWinRT**, a library from [Microsoft’s GitHub repository](https://github.com/morningstarxcdcode/CsWinRT).

## Features

- System info scanner using **WinRT** and **WMI**
- UAC, Firewall, and Antivirus check
- Auto hardening (disable SMBv1, enable firewall rules)
- Export system reports
- Easy CLI interface

## How This Project Uses **CsWinRT**

This project integrates **CsWinRT** to interact with Windows Runtime APIs for security-related operations. By using **CsWinRT**, we ensure compatibility with the Windows runtime environment and enable the system to dynamically enhance security features.

## Related Projects

- [Microsoft CsWinRT](https://github.com/microsoft/CsWinRT) - The official repository for **CsWinRT**.

## Running Tests

This project includes test functions for each component. To run tests, execute the individual files as scripts or compile and run the C++ programs with the test main functions.

- C++: Compile and run `threat_level_analyzer.cpp`, `log_monitor.cpp`, and `main.cpp` (with test functions).
- Python: Run `MITRE_Log_Mapper.py`, `CVE_Lookup_API.py`, and `Auto_Report_Generator.py` to execute their test functions.
- C#: Use the `TestSystemChecks` method in `Program.cs` or run the program normally.

## Author

This project is authored and maintained by **morningstarxcd**.

## License

[Specify your license here]

## Updated on: 2025-04-16
=======

---

# **WinRT System Hardener** 🛡️⚙️

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen?style=for-the-badge)](https://github.com/morningstarxcdcode/WinRTSystemHardener)  
[![License: MIT](https://img.shields.io/badge/license-MIT-blue?style=for-the-badge)](LICENSE)  
[![Version](https://img.shields.io/badge/version-1.0.0-blue?style=for-the-badge)](https://github.com/morningstarxcdcode/WinRTSystemHardener)  
[![Contributors](https://img.shields.io/github/contributors/morningstarxcdcode/WinRTSystemHardener?style=for-the-badge)](https://github.com/morningstarxcdcode/WinRTSystemHardener/graphs/contributors)  
[![Stars](https://img.shields.io/github/stars/morningstarxcdcode/WinRTSystemHardener?style=for-the-badge)](https://github.com/morningstarxcdcode/WinRTSystemHardener/stargazers)

### **Auto Recon + System Hardening Tool Using Windows Runtime APIs**

Welcome to **WinRT System Hardener** – a **powerful security tool** designed to enhance your system’s security using **Windows Runtime APIs** and **CsWinRT**. This tool is specifically built to make Windows environments more secure by leveraging advanced scanning and auto hardening features.

---

## 🏗️ **Table of Contents**

- [Features](#features)
- [Technologies Used](#technologies-used)
- [Installation](#installation)
- [Usage](#usage)
- [System Requirements](#system-requirements)
- [How This Project Uses **CsWinRT**](#how-this-project-uses-cswinrt)
- [Exported Reports](#exported-reports)
- [CLI Interface](#cli-interface)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)
- [Related Projects](#related-projects)
- [Screenshots](#screenshots)
- [Acknowledgements](#acknowledgements)
- [Support](#support)

---

## 🚀 **Features**

<div align="center">
  <img src="https://media.giphy.com/media/3oKIPnAiaMCws8nOsE/giphy.gif" alt="System Scan Animation" width="400px"><br>
  <em>Dynamic system scanning in action!</em>
</div>

- **System Info Scanner**:  
  Gathers detailed system information using **WinRT** and **WMI**.  
  Get insights into OS, hardware, network status, and more.

- **UAC, Firewall, and Antivirus Check**:  
  Automatically checks the status of **User Account Control (UAC)**, **Windows Firewall**, and **Antivirus software**.

- **Auto Hardening**:  
  Automatically enforces essential security settings:
  - Disables **SMBv1**
  - Enables **Windows Firewall** rules
  - Configures **Windows Defender Antivirus** policies

- **Export System Reports**:  
  Generate **JSON** or **CSV** formatted reports of your system's configuration, hardening status, and more.

- **Interactive CLI Interface**:  
  Engage with an interactive command-line interface with live feedback and real-time updates.

---

## 💻 **Technologies Used**

- **CsWinRT**: Windows Runtime APIs integration, providing enhanced security capabilities.
- **WMI (Windows Management Instrumentation)**: System health and data retrieval.
- **.NET 5.0+**: The core framework used to build the application.
- **PowerShell**: For automating system checks and commands.
- **JSON/CSV**: For exporting detailed system data and audit results.
- **Windows API**: Deep access to Windows features for system hardening.

---

## 🛠️ **Installation**

### Prerequisites

- **Operating System**: Windows 10/11 (64-bit) or Windows Server 2016+
- **.NET SDK**: Version 5.0 or higher.
- **Visual Studio** or **VS Code** for development.

### Installation Steps

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/morningstarxcdcode/WinRTSystemHardener.git
   ```

2. **Navigate to the Project Directory**:
   ```bash
   cd WinRTSystemHardener
   ```

3. **Restore Dependencies**:
   ```bash
   dotnet restore
   ```

4. **Build the Project**:
   ```bash
   dotnet build
   ```

5. **Run the Project**:
   ```bash
   dotnet run
   ```

---

### 📦 **Publish as an Executable**

If you'd like to package the tool as a standalone executable, you can publish it with the following command:
```bash
dotnet publish -c Release -r win-x64 --self-contained
```

This will generate an executable that you can run on other Windows systems without needing to install .NET.

---

## 🏃‍♂️ **Usage**

### CLI Commands

- **Perform a Full System Scan**:
  ```bash
  WinRTSystemHardener scan
  ```

- **Check UAC, Firewall, Antivirus Status**:
  ```bash
  WinRTSystemHardener check
  ```

- **Execute Auto Hardening**:
  ```bash
  WinRTSystemHardener harden
  ```

- **Generate System Report (JSON Format)**:
  ```bash
  WinRTSystemHardener report --format json
  ```

- **Generate System Report (CSV Format)**:
  ```bash
  WinRTSystemHardener report --format csv
  ```

---

## 🧩 **How This Project Uses CsWinRT**

This project integrates **CsWinRT** for seamless interaction with Windows Runtime APIs. **CsWinRT** enables us to leverage the latest Windows 10/11 APIs in a safe, efficient manner. Here’s how it works:

- **Windows Management Instrumentation (WMI)**:  
  We use **WMI** to fetch system data such as OS version, network adapters, and disk status.

- **Windows Runtime APIs**:  
  Security policies (e.g., disabling SMBv1) and other features are controlled via **Windows Runtime APIs** provided by **CsWinRT**.

---

## 📊 **Exported Reports**

After a system scan, you can export reports in two formats:

- **JSON Report**:  
  A machine-readable format for detailed logging and auditing.
  ```json
  {
    "SystemInfo": {
      "OS": "Windows 10 Pro",
      "Version": "19041",
      "SMBv1": "Disabled"
    },
    "SecurityPolicies": {
      "Firewall": "Enabled",
      "Antivirus": "Windows Defender"
    }
  }
  ```

- **CSV Report**:  
  Easily importable into spreadsheet applications for analysis.

---

## ⚙️ **CLI Interface**

Enjoy an **interactive and dynamic CLI** experience with real-time feedback:
```bash
WinRTSystemHardener check --firewall --uac
```

This command checks the firewall and UAC status, with live updates on your terminal.

---

## 💡 **Examples**

### Example of System Scan
```bash
$ WinRTSystemHardener scan
Scanning your system...
OS: Windows 10 Pro
SMBv1: Disabled
Firewall: Enabled
Antivirus: Windows Defender
UAC: Enabled
```

### Example of Auto Hardening Action
```bash
$ WinRTSystemHardener harden
Disabling SMBv1...
Enabling Firewall...
Configuring Windows Defender...
```

---

## 🤝 **Contributing**

We welcome contributions from the community! To contribute:

1. **Fork the repository**
2. **Create a new branch**:
   ```bash
   git checkout -b feature/cool-animation
   ```
3. **Make your changes** and commit:
   ```bash
   git commit -am 'Added animation to CLI output'
   ```
4. **Push your changes**:
   ```bash
   git push origin feature/cool-animation
   ```
5. **Open a Pull Request**

For any **bug reports**, please open an issue on GitHub.

---

## 📝 **License**

This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.

---

## 🌐 **Related Projects**

- [Microsoft CsWinRT](https://github.com/microsoft/CsWinRT) – Official repository for **CsWinRT**.
- [PowerShell](https://github.com/PowerShell/PowerShell) – Automate your Windows management tasks.
- [Windows API Documentation](https://learn.microsoft.com/en-us/windows/win32/api/) – In-depth details on Windows API usage.

---

## 📸 **Screenshots**

Check out these cool animations that showcase how the system works in action!

<div align="center">
  <img src="https://media.giphy.com/media/xT9IgzoKnwFNmISR8I/giphy.gif" alt="System Scan Report Animation" width="400px"><br>
  <em>System Scan Report Animation</em>
</div>

<div align="center">
  <img src="https://media.giphy.com/media/3oEjI6SIIHBdRxXI40/giphy.gif" alt="Hardening in Action" width="400px"><br>
  <em>Auto Hardening Process Animation</em>
</div>

---

## 🙏 **Acknowledgements**

- **Microsoft**: For the amazing **CsWinRT** library and Windows Runtime APIs.
- **Windows API**: For providing deep access to Windows security features.
- **PowerShell**: For automating system checks and configurations.

---

## 🆘 **Support**

If you encounter any issues, please feel free to open an issue on [GitHub Issues](https://github.com/morningstarxcdcode/WinRTSystemHardener/issues).

---
>>>>>>> origin/main
