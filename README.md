TCP Port Checker & Network Scanner

A high-performance, lightweight Python utility designed to scan, diagnose, and audit network ports. This tool helps network administrators and security professionals quickly identify open TCP ports, test service availability, and detect host reachability.

Key Features

Multi-Port Scanning: Supports single ports, comma-separated lists, and continuous port ranges (e.g., 80, 80,443,8080, or 1-1024).

Custom Timeout Handling: Prevents network hangs by allowing customizable connection timeout thresholds.

Service Identification: Automatically maps standard open ports to common services (HTTP, HTTPS, SSH, FTP, RDP, DNS, etc.).

Zero External Dependencies: Built entirely using Python's standard socket and argparse libraries for maximum portability across Windows, Linux, and macOS.

Clean Terminal Output: Formatted CLI tables showing immediate status (OPEN, CLOSED, or TIMED OUT / FILTERED).

Technical Architecture

The utility uses non-blocking TCP socket streams via socket.socket(socket.AF_INET, socket.SOCK_STREAM) to initiate a standard 3-way handshake (SYN -> SYN-ACK -> ACK).

OPEN: The remote target accepted the TCP connection (SYN-ACK received).

CLOSED: The target explicitly refused the connection (RST packet returned).

FILTERED / TIMED OUT: No response was received within the specified timeout, indicating firewall rules or dropped packets.

Prerequisites

Operating System: Windows, Linux, or macOS.

Python: Python 3.6 or higher (No third-party packages required).

Installation & Setup

Clone the repository:

git clone https://github.com/your-username/tcp-port-checker.git
cd tcp-port-checker


Verify Python installation:

python --version


Usage

Run the scanner directly from your command prompt or terminal:

Basic Scan (Single Port)

python port_checker.py --host 192.168.1.1 --port 80


Scan Multiple Specific Ports

python port_checker.py --host 192.168.1.1 --port 22,80,443,3389


Range Scan

python port_checker.py --host 192.168.1.1 --start-port 1 --end-port 1024


Custom Timeout (Default: 2 seconds)

python port_checker.py --host example.com --port 443 --timeout 1.0


Example Output

[*] Starting TCP Port Scan for target: 192.168.1.1
[*] Timeout threshold set to: 2.0s
--------------------------------------------------
PORT     | STATUS   | SERVICE
--------------------------------------------------
22/tcp   | OPEN     | SSH
80/tcp   | OPEN     | HTTP
443/tcp  | OPEN     | HTTPS
3389/tcp | CLOSED   | RDP
8080/tcp | FILTERED | HTTP-ALT
--------------------------------------------------
[+] Scan complete. 3 open ports detected.


Project Structure

tcp-port-checker/
│
├── port_checker.py      # Core execution script and socket logic
├── README.md            # Complete project documentation and manual
└── requirements.txt     # Optional (Standard library implementation)


Portfolio Context

This project highlights core concepts in computer networking, TCP/IP protocol stack behavior, low-level socket handling, and command-line tool engineering for cybersecurity and system administration portfolios.

License

This project is open-source under the MIT License.
