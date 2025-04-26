#include "mult_div_unit.h"
#include <stdio.h>
#include <string.h>

void mult_div_unit()
{
    int a, b;
    char op[10];
    printf("Enter operation (mult, div): ");
    scanf("%s", op);

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    if (strcmp(op, "mult") == 0)
    {
        printf("Result: %d\n", a * b);
    }
    else if (strcmp(op, "div") == 0)
    {
        if (b != 0)
        {
            printf("Result: %d\n", a / b);
        }
        else
        {
            printf("Error: Division by zero\n");
        }
    }
    else
    {
        printf("Unknown operation\n");
    }
}