
#include "monty.h"
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
		{"pint", print_dlistint},
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
