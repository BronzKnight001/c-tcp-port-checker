#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <target_ip> <port>\n", argv[0]);
        return 1;
    }

    char *target_ip = argv[1];
    int port = atoi(argv[2]);

    // initialize  winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("[-] WSAStartup failed: %d\n", iResult);  
        return 1;
    }

    // create socket
    SOCKET ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("[-] Socket creation  failed: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    struct sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr(target_ip); 
    clientService.sin_port = htons(port);

    printf("[*] Testing TCP connection to %s on port %d...\n", target_ip, port);

    // attempt connection
    iResult = connect(ConnectSocket, (SOCKADDR*)&clientService, sizeof(clientService));
    if (iResult == SOCKET_ERROR) {
        printf("[-] Port %d on %s is CLOSED (or filtered).\n", port, target_ip);  
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    printf("[+] SUCCESS: Port %d on %s is OPEN!\n", port, target_ip);

    closesocket(ConnectSocket);
    WSACleanup();
    return 0;
}

