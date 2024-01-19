#include "monty.h"
/**
 * _print_rev - print list rev
 * @h: list to print
 * Return: list length
 */
void _print_rev(stack_t *h)
{

	if (h != NULL)
	{
		fprintf(stdout, "%d\n", (h)->n);

		_print_rev((h)->next);
	}
}

/**
 * print_dlistint - print list with length
 * @h: list to print
 * @n: line number
 * Return: list length
 */
void print_dlistint(stack_t **h, unsigned int n)
{

	stack_t *current = *h;

	(void)n;



		while (current != NULL)
		{
			fprintf(stdout, "%d\n", current->n);
			current = current->next;
		}
}
