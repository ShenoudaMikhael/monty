#include <stdio.h>
#include <stdlib.h>
/**
 * free_line - free the readline ptr
 * @status: on exit
 * @argv: line ptr
 * Return: void
 */
void free_line(int status, void *argv)
{
	char **line = argv;

	(void)status;

	if (*line != NULL)
	{
		free(*line);
	}
}
