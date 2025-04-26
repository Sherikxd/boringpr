#include "logic_unit.h"
#include <stdio.h>
#include <string.h>

void logic_unit()
{
    int a, b;
    char op[10];
    printf("Enter operation (and, or, not, xor): ");
    scanf("%s", op);

    if (strcmp(op, "not") == 0)
    {
        printf("Enter a: ");
        scanf("%d", &a);
        printf("Result: %d\n", ~a);
    }
    else
    {
        printf("Enter a and b: ");
        scanf("%d %d", &a, &b);
        if (strcmp(op, "and") == 0)
        {
            printf("Result: %d\n", a & b);
        }
        else if (strcmp(op, "or") == 0)
        {
            printf("Result: %d\n", a | b);
        }
        else if (strcmp(op, "xor") == 0)
        {
            printf("Result: %d\n", a ^ b);
        }
        else
        {
            printf("Unknown operation\n");
        }
    }
}