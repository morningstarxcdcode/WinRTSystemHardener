# Author: morningstarxcd
import requests
import time
import json
from typing import Dict, Union

def fetch_cve_from_nvd(cve_id: str) -> Union[Dict[str, Union[str, float]], Dict[str, str]]:
    """
    Fetch CVE details from the NVD API.
    Returns a dictionary with CVE details or an error message.
    """
    url = "https://services.nvd.nist.gov/rest/json/cves/1.0"
    params = {"keyword": cve_id}
    try:
        response = requests.get(url, params=params, timeout=10)
        response.raise_for_status()
        cve_data = response.json()

        if 'result' in cve_data and 'CVE_Items' in cve_data['result'] and cve_data['result']['CVE_Items']:
            for item in cve_data['result']['CVE_Items']:
                if item['cve']['CVE_data_meta']['ID'] == cve_id:
                    description = item['cve']['description']['description_data'][0]['value']
                    score = item.get('impact', {}).get('baseMetricV3', {}).get('cvssV3', {}).get('baseScore', "N/A")
                    severity = item.get('impact', {}).get('baseMetricV3', {}).get('cvssV3', {}).get('baseSeverity', "N/A")
                    return {
                        "cve_id": cve_id,
                        "description": description,
                        "score": score,
                        "severity": severity
                    }
            return {"error": f"CVE ID {cve_id} not found in the API response."}
        return {"error": "CVE data not found or incomplete"}
    except requests.exceptions.HTTPError as e:
        if response.status_code == 404:
            return {"error": f"CVE ID {cve_id} not found in the NVD database."}
        return {"error": f"HTTP error occurred: {str(e)}"}
    except requests.exceptions.RequestException as e:
        return {"error": f"Request failed: {str(e)}"}
    except KeyError as e:
        return {"error": f"Unexpected data structure: {str(e)}"}
    except json.JSONDecodeError as e:
        return {"error": f"JSON decode error: {str(e)}"}
    except Exception as e:
        return {"error": f"An unexpected error occurred: {str(e)}"}

def test_fetch_cve_from_nvd():
    """
    Test the fetch_cve_from_nvd function with a sample CVE ID.
    """
    cve_id = "CVE-2024-3094"
    result = fetch_cve_from_nvd(cve_id)
    if "error" in result:
        print(f"Error: {result['error']}")
    else:
        print(f"CVE ID: {result['cve_id']}")
        print(f"Description: {result['description']}")
        print(f"Score: {result['score']}")
        print(f"Severity: {result['severity']}")

if __name__ == "__main__":
    test_fetch_cve_from_nvd()
    time.sleep(1)
