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

	a = (strtok(NULL, "\n\t\r "));
	for (c = 0; c < strlen(a); c++)
	{
		res = isdigit(a[c]);
		if (res == 0)
			break;
	}

	if (a == NULL || res == 0)
	{

		fprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}

	if (tmp == NULL)
	{
		return;
	}

	tmp->n = n;

	tmp->prev = NULL;
	tmp->next = *head;

	if (*head != NULL)
		(*head)->prev = tmp;

	*head = tmp;

	return;
}
