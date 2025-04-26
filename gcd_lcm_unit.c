#include "gcd_lcm_unit.h"
#include <stdio.h>
#include <string.h>
// Función para calcular el MCD utilizando el algoritmo de Euclides
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Función para calcular el MCM utilizando el MCD
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

void gcd_lcm_unit()
{
    int a, b;
    char op[10];
    printf("Enter operation (gcd, lcm): ");
    scanf("%s", op);

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    if (strcmp(op, "gcd") == 0)
    {
        printf("GCD: %d\n", gcd(a, b));
    }
    else if (strcmp(op, "lcm") == 0)
    {
        printf("LCM: %d\n", lcm(a, b));
    }
    else
    {
        printf("Unknown operation\n");
    }
}