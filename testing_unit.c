#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib") // Vincula la biblioteca Winsock

void testing_unit()
{
    char hostname[256];

    // Inicializar Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        fprintf(stderr, "Error al inicializar Winsock\n");
        return;
    }

    // Obtener el nombre del host
    if (gethostname(hostname, sizeof(hostname)) != 0)
    {
        fprintf(stderr, "Error al obtener el nombre del host\n");
        WSACleanup();
        return;
    }

    // Mostrar la información
    printf("=== Información del sistema ===\n");
    printf("Nombre del host: %s\n", hostname);

    // Limpiar Winsock
    WSACleanup();
}