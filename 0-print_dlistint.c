#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

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
		dprintf(STDERR_FILENO, "%d\n", current->n);
		current = current->next;
	}
}
