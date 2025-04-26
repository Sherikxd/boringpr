#include "prob_unit.h"
#include <string.h>
#include <stdio.h>

double calcular_probabilidad(int ocurrencias, int total_resultados)
{
    if (total_resultados == 0)
    {
        return 0.0; // Evitar división por cero
    }
    return (double)ocurrencias / total_resultados;
}

void prob_unit()
{
    int ocurrencias, total_resultados;

    // Pedir al usuario el número de ocurrencias del evento
    printf("Ingrese el numero de ocurrencias del evento: ");
    scanf("%d", &ocurrencias);

    // Pedir al usuario el número total de posibles resultados
    printf("Ingrese el numero total de resultados posibles: ");
    scanf("%d", &total_resultados);

    // Calcular la probabilidad
    double probabilidad = calcular_probabilidad(ocurrencias, total_resultados);

    // Mostrar el resultado
    printf("La probabilidad del evento es: %f\n", probabilidad);
}