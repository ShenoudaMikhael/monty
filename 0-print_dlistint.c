#include <stddef.h>
#include <stdio.h>
#include "monty.h"
/**
 * print_dlistint - print list with len
 * @h: list to print
 * Return: list length
 */
void print_dlistint(stack_t **h, unsigned int n)
{
	size_t i = 0;

	(void)n;

	while (h != NULL)
	{

		i++;
		fprintf(stdout, "%d\n", (*h)->n);

		if ((*h)->next == NULL)
			break;
		*h = (*h)->next;
	}
	return;
}
