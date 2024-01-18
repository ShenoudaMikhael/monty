
#include "monty.h"

void _stack(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
	is.stack = 1;
}
void _queue(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
	is.stack = 0;
}

/**
 * do_op - compare token to operation
 * @stack: stack
 * @line: has the data
 * @n: line number
 * Return: None
 */
void do_op(stack_t **stack, char *line, int n)
{
	int i = 0;
	instruction_t instruction[] = {
		{"push", add_dnodeint},
		{"pall", print_dlistint},
		{"pint", _pint},
		{"nop", _nop},
		{"pop", _pop},
		{"add", _add},
		{"swap", _swap},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL},
	};

	while (instruction[i].opcode != NULL)
	{
		if (strcmp(instruction[i].opcode, line) == 0)
		{

			instruction[i].f(stack, n);

			return;
		}

		i++;
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", n, line);
	exit(EXIT_FAILURE);
}
