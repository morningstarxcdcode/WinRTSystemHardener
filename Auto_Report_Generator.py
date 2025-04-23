from typing import Dict, List, Any
from fpdf import FPDF
import pandas as pd

def generate_pdf_report(data: Dict[str, Any], filename: str = "report.pdf") -> None:
    """
    Generate a PDF report from the given data.
    """
    pdf = FPDF()
    pdf.add_page()
    pdf.set_font("Arial", size=12)

    pdf.cell(200, 10, txt="Threat Analysis Report", ln=True, align='C')
    pdf.ln(10)  # Add a line break

    for key, value in data.items():
        pdf.cell(200, 10, txt=f"{key}: {value}", ln=True)

    pdf.output(filename)
    print(f"PDF report generated: {filename}")

def generate_csv_report(log_entries: List[Dict[str, Any]], filename: str = "report.csv") -> None:
    """
    Generate a CSV report from the given log entries.
    """
    df = pd.DataFrame(log_entries)
    df.to_csv(filename, index=False)
    print(f"CSV report generated: {filename}")

def test_report_generators() -> None:
    """
    Test the PDF and CSV report generators with example data.
    """
    pdf_data = {
        "Date": "2025-04-13",
        "Total Logs Analyzed": 150,
        "High Threats": 5,
        "Medium Threats": 10,
        "Low Threats": 135
    }
    generate_pdf_report(pdf_data)

    csv_data = [
        {"Log": "powershell executed", "Threat Level": "High", "MITRE Technique": "T1059"},
        {"Log": "mimikatz detected", "Threat Level": "High", "MITRE Technique": "T1003"},
        {"Log": "ping command used", "Threat Level": "Medium", "MITRE Technique": "T1046"},
        {"Log": "whoami executed", "Threat Level": "Medium", "MITRE Technique": "T1033"}
    ]
    generate_csv_report(csv_data)

if __name__ == "__main__":
    test_report_generators()
