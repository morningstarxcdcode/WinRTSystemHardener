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
}
