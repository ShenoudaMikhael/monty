#include "monty.h"
gvar_t is;
/**
 * closefile - close file
 * @status: from on exit
 * @f: file
 * Return: void
 */
void closefile(int status, void *f)
{
	FILE *fo = (FILE *)f;

	(void)status;
	if (fo != NULL)
		fclose(f);
}

/**
 * replaceNewlineWithNull - remove new line
 * @str: string
 * Return: Void
 */
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

/**
 * main - main function
 * @argc: argument count
 * @argv: arguments
 * Return: int
 */
int main(int argc, char const **argv)
{
	int n = 0;
	FILE *fo = NULL;
	char *line = NULL, *tok = NULL;
	size_t len;
	stack_t *stack = NULL;

	is.stack = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fo = fopen(argv[1], "r");
	if (fo == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	on_exit(closefile, fo);
	on_exit(free_dlistint, &stack);
	on_exit(free_line, &line);

	while ((getline(&line, &len, fo)) != -1)
	{

		n++;
		tok = strtok(line, "\n\t\r ");

		if (tok != NULL && tok[0] != '#')
		{

			do_op(&stack, tok, n);
		}
	}
	exit(EXIT_SUCCESS);
}
