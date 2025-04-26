/*
 *Copyright (C) 2023  Sherikxd
 *Comandos exprimentales... :p
 **/
#include "testing_unit.h"
/*
 * Librerias Usadas
 */
#include <stdio.h>
#include <string.h>

void experimental_menu()
{
    char command[100];
    while (1)
    {
        printf("Enter command (testing, exit): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "testing") == 0)
        {
            testing_unit();
        }
        else
        {
            printf("Unknown command\n");
        }
    }
}