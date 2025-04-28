#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

void net_unit() {
    WSADATA wsa;
    SOCKET raw_socket;
    char buffer[65536];
    struct sockaddr_in source;
    int source_size = sizeof(source);

    printf("=== Escaneo de tráfico de red ===\n");

    // Inicializar Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Error al inicializar Winsock: %d\n", WSAGetLastError());
        return;
    }

    // Crear un socket RAW
    raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
    if (raw_socket == INVALID_SOCKET) {
        printf("Error al crear el socket: %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    // Configurar el socket para capturar tráfico en la interfaz local
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = 0;
    local.sin_addr.s_addr = INADDR_ANY;

    if (bind(raw_socket, (struct sockaddr *)&local, sizeof(local)) == SOCKET_ERROR) {
        printf("Error al enlazar el socket: %d\n", WSAGetLastError());
        closesocket(raw_socket);
        WSACleanup();
        return;
    }

    printf("Socket creado y enlazado correctamente.\n");

    // Capturar paquetes
    for (int i = 0; i < 5; i++) { // Capturar 5 paquetes para prueba
        int data_size = recvfrom(raw_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&source, &source_size);
        if (data_size == SOCKET_ERROR) {
            printf("Error al recibir datos: %d\n", WSAGetLastError());
            break;
        }

        printf("Paquete recibido de: %s\n", inet_ntoa(source.sin_addr));
    }

    // Cerrar el socket y limpiar Winsock
    closesocket(raw_socket);
    WSACleanup();


    printf("Escaneo finalizado.\n");
}