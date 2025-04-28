/*
Comandos o funcionalidades :D
*/
#include "controller.h"
#include "logic_unit.h"
#include "arithmetic_unit.h"
#include "mult_div_unit.h"
#include "functions_unit.h"
#include "gcd_lcm_unit.h"
#include "permute_unit.h"
#include "io.h"
#include "prob_unit.h"
#include "experimental_menu.h"
/*
librerias
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void start_simulation()
{   
    printf("        .__________________________.\n");
    printf("        | .___________________.  |==|\n");
    printf("        | |     _           _    |  |\n");
    printf("        | |    |_)         (_|   |  |\n");
    printf("        | |                      |  |\n");
    printf("        | |   °______________°   |  |\n");
    printf("        | |______________________|  |\n");
    printf("        !___________________________!\n");
    printf("         /                           \\\n");
    printf("        /  [][][][][][][][][][][][][]  \\\n");
    printf("       /  [][][][][][][][][][][][][][]  \\\n");
    printf("      /  [][][][][][][][][][][][][][][]  \\\n");
    printf("     /  [][][][][][][][][][][][][][][][]  \\\n");
    printf("    /  [][][][][][][][][][][][][][][][][]  \\\n");
    printf("   /_______________________________________\\\n");

    char command[100];
    while (1)
    {
        printf("Enter command (logic, arithmetic, multdiv, function,prob, gcd_lcm,permute, exit) \      n ");
        printf("**/exp/** para probrar menu de funciones exprimentales\n >>>");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "logic") == 0)
        {
            logic_unit();
        }
        else if (strcmp(command, "arithmetic") == 0)
        {
            arithmetic_unit();
        }
        else if (strcmp(command, "multdiv") == 0)
        {
            mult_div_unit();
        }
        else if (strcmp(command, "function") == 0)
        {
            functions_unit();
        }
        else if (strcmp(command, "gcd_lcm") == 0)
        {
            gcd_lcm_unit();
        }
        else if (strcmp(command, "permute") == 0)
        {
            permute_unit();
        }
        else if (strcmp(command, "prob") == 0)
        {
            prob_unit();
        }
        else if (strcmp(command, "exp") == 0) {
            experimental_menu();
        }
        else
        {
            printf("Unknown command\n");
        }
    }
}