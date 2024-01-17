#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "monty.h"
void do_op(stack_t **stack, char *line, int n)
{
    int i = 0;
    char *a;
    instruction_t instruction[] = {
        {"push", add_dnodeint},
        {"pall", print_dlistint},
        {NULL, NULL},
    };

    while (instruction[i].opcode != NULL)
    {
        if (strcmp(instruction[i].opcode, line) == 0)
        {

            a = (strtok(NULL, "\n\t\r "));
            if (a)
            {

                instruction[i]
                    .f(stack, atoi(a));
            }
            else
            {

                instruction[i]
                    .f(stack, 0);
            }
            return;
        }

        i++;
    }
    fprintf(stderr, "L%d: unknown instruction %s\n", n, line);
    exit(EXIT_FAILURE);
}
