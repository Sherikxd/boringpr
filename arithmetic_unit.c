#include "arithmetic_unit.h"
#include <stdio.h>
#include <string.h>

void arithmetic_unit()
{
    int a, b;
    char op[10];
    printf("Enter operation (add, sub): ");
    scanf("%s", op);

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    if (strcmp(op, "add") == 0)
    {
        printf("Result: %d\n", a + b);
    }
    else if (strcmp(op, "sub") == 0)
    {
        printf("Result: %d\n", a - b);
    }
    else
    {
        printf("Unknown operation\n");
    }
}