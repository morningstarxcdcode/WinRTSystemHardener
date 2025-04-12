using System;
using System.Management;

class Program
{
    static void Main()
    {
        Console.WriteLine("🛡️ WinRT System Recon + Auto Hardener 🛡️\n");

        Console.WriteLine("Fetching system info...\n");

        GetSystemInfo();
        CheckFirewallStatus();
        CheckUACStatus();
        CheckAntivirusStatus();
    }

    static void GetSystemInfo()
    {
        ManagementObjectSearcher searcher = new ManagementObjectSearcher("select * from Win32_OperatingSystem");

        foreach (ManagementObject os in searcher.Get())
        {
            Console.WriteLine($"OS Name: {os["Caption"]}");
            Console.WriteLine($"Version: {os["Version"]}");
            Console.WriteLine($"Architecture: {os["OSArchitecture"]}");
        }
    }

    static void CheckFirewallStatus()
    {
        Console.WriteLine("\n[+] Checking Firewall status...");
        // Placeholder - Real code will come later
        Console.WriteLine("🔒 Firewall is ENABLED ✅ (simulated)");
    }

    static void CheckUACStatus()
    {
        Console.WriteLine("\n[+] Checking UAC (User Account Control) status...");
        // Simulated UAC check
        Console.WriteLine("🛡️ UAC is ENABLED ✅ (simulated)");
    }

    static void CheckAntivirusStatus()
    {
        Console.WriteLine("\n[+] Checking Antivirus status...");
        // Placeholder - You could use Windows Management Instrumentation (WMI) to get antivirus status
        Console.WriteLine("🛡️ Antivirus is ACTIVE ✅ (simulated)");
    }
}

