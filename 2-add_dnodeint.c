#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "monty.h"
/**
 * add_dnodeint - add node at the begining
 * @head: dlist
 * @n: number
 * Return: address or Null
 */
void add_dnodeint(stack_t **head, unsigned int n)
{
	size_t c = 0, res = 0;
	stack_t *tmp = malloc(sizeof(stack_t));
	char *a = NULL;

	if (tmp == NULL)
	{
		dprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	a = (strtok(NULL, "\n\t\r "));
	if (a == NULL)
	{
		dprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}

	for (c = 0; c < strlen(a); c++)
	{
		res = isdigit(a[c]);
		if (res == 0)
			break;
	}

	if (res == 0)
	{

		dprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}

	if (tmp == NULL)
	{
		return;
	}

	tmp->n = atoi(a);

	tmp->prev = NULL;
	tmp->next = *head;

	if (*head != NULL)
		(*head)->prev = tmp;

	*head = tmp;

	return;
}
