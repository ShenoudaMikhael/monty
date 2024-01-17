#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "monty.h"

void replaceNewlineWithNull(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
        }
    }
}
int main(int argc, char const **argv)
{
    int n = 0;
    FILE *fo;
    char *line;
    size_t len;
    ssize_t read;
    instruction_t instruction[] = {
        {"push", add_dnodeint},
        {"pall", print_dlistint},
        {"\0", NULL},
    };
    /* if no file provided or more than 2 arguments */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    /* open file */
    fo = fopen(argv[1], "r");
    /* if fail to open file */
    if (fo == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    /* get file line by line */
    while ((read = getline(&line, &len, fo)) != -1)
    {
        n = 0;

        while (read != -1 && instruction[n].opcode != NULL)
        {

            if (strcmp(instruction[n].opcode, strtok(strdup(line), " \n")) == 0)
            {
                printf("%s\n", strtok(NULL, " \n"));
                n++;
                continue;
            }
            else if (strcmp(instruction[n].opcode, strtok(strdup(line), "\n")) == 0)
            {
                printf("%s\n", "AA");

                n++;
                continue;
            }
            printf("NOOOO");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fo);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
