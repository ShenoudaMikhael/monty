#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "monty.h"

void closefile(int status, void *f)
{
    (void)status;

    if (f != NULL)
        fclose(f);
}

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
    char *line, *tok;
    size_t len;

    stack_t *stack = NULL;
    /* if no file provided or more than 2 arguments */

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    /* open file */
    fo = fopen(argv[1], "r");
    /* if fail to open file */
    if (fo == NULL)
    {

        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    on_exit(free_dlistint, &stack);
    on_exit(free_line, &line);
    on_exit(closefile, fo);

    /* get file line by line */
    while ((getline(&line, &len, fo)) != -1)
    {

        n++;
        tok = strtok(line, "\n\t\r ");
        if (tok != NULL)
        {

            do_op(&stack, tok, n);
        }
    }

    exit(EXIT_SUCCESS);
}
