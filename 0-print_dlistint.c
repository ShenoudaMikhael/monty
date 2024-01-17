#include "monty.h"

/**
 * print_dlistint - print list with len
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
		printf("%d\n", current->n);
		current = current->next;
	}
}
