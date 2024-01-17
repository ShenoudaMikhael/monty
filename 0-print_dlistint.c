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

	stack_t *current = *h;

	(void)n;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
