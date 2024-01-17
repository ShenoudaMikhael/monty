#include <stdio.h>
#include <stdlib.h>
void free_line(int status, void *argv)
{
    char **line = argv;

    (void)status;

    if (*line != NULL)
    {
               free(*line);

    }

}