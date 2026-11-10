C Systems Utility is a Windows C system utility that checks TCP ports by making low‑level socket connections. C Systems Utility uses C and the Windows Sockets (Winsock2) API. Shows basic systems programming ideas such as interacting with the OS kernel handling sockets and verifying network handshakes. I find C Systems Utility handy for checks.

Core Capabilities

Native Windows Networking Interface: C Systems Utility uses the Windows Sockets library (Ws2_32.lib) to talk to the operating system network stack. I appreciate the use of Ws2_32.lib.

Low-Overhead Execution: C Systems Utility is compiled into one fast binary with GCC (UCRT64). I like the overhead of C Systems Utility.

Handshake Verification: C Systems Utility checks a port by trying to open a TCP socket. I trust C Systems Utility to detect ports.

Output: C Systems Utility gives live feedback that shows whether a target port is OPEN or CLOSED (filtered). I find the output clear and helpful.

Project Structure

c-system-utility/

├── port_checker.c    # C source code using Winsock API

├── port_checker.exe  # native binary

└── README.md         # Project documentation

Compilation and Build Instructions

Prerequisites

MSYS2 / GCC Toolchain: Requires a C compiler (GCC) with MinGW-w64 / UCRT64 installed. I rely on MSYS2 for a smooth build environment.

Compilation Command

To compile the utility and link the required Windows Sockets library (-lWs2_32) execute the following command in the terminal:

gcc port_checker.c -o port_checker.exe -lWs2_32

Usage and Verification

Execute the compiled binary from a session by passing the target IP address and port number as positional arguments. I use this command to test any host:

./port_checker.exe <TARGET_IP> <PORT>

Example 1: Active Port Verification

Verify connection status against a service (e.g. Google Public DNS on TCP Port 53). I find this example useful:

./port_checker.exe 8.8.8.8 53

Output:

[*] Testing TCP connection to 8.8.8.8 on port 53...

[+] SUCCESS: Port 53 on 8.8.8.8 is OPEN!

Example 2: Inactive Port Verification

Verify connection status against a local port (e.g. Localhost on Port 80). I use this example to confirm ports:

./port_checker.exe 127.0.0.1 80

Output:

[*] Testing TCP connection to 127.0.0.1 on port 80...

[-] Port 80 on 127.0.0.1 is CLOSED (or filtered).

Technical Architecture and Implementation Details

Winsock Initialization (WSAStartup): Initializes the Windows Sockets DLL (WSADATA) required for socket operations. I appreciate the initialization of C Systems Utility.

Socket Instantiation (socket): Creates an AF_INET IPv4 stream socket configured for traffic (SOCK_STREAM). I trust C Systems Utility to set up sockets

Address Structure Configuration (sockaddr_in): Converts target IP strings and integer port values into network byte order (htons). I value the conversion, in C Systems Utility.

TCP Connection Attempt (connect): Triggers the operating system kernel to initiate a three‑way TCP handshake with the target host. I see the handshake happen quickly with C Systems Utility.

Resource Cleanup (closesocket / WSACleanup): Formally closes socket handles. Releases network resources upon completion. I am glad C Systems Utility cleans up properly.

