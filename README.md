# WinRT System Hardener

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

## License

[Specify your license here]

## Updated on: 2025-04-16
