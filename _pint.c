#include "monty.h"
/**
 * _pint - print list head
 * @head: list head
 * @n: current line
 *
 */
void _pint(stack_t **head, unsigned int n)
{
	
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*head)->n);
}
