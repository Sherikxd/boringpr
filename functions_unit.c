#include "functions_unit.h"
#include <stdio.h>
#include <math.h>

void functions_unit()
{
    int choice;
    printf("Choose function (1: sin, 2: cos, 3: tan): ");
    scanf("%d", &choice);

    double value;
    printf("Enter value: ");
    scanf("%lf", &value);

    switch (choice)
    {
    case 1:
        printf("Result: %f\n", sin(value));
        break;
    case 2:
        printf("Result: %f\n", cos(value));
        break;
    case 3:
        printf("Result: %f\n", tan(value));
        break;
    default:
        printf("Unknown function\n");
        break;
    }
}
