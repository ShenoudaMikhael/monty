#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
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
	char *a = NULL, *b;

	if (tmp == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	a = strtok(NULL, "\n\t\r ");

	if (a == NULL)
	{
		dprintf(STDOUT_FILENO, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}

	for (c = 0; c < strlen(a); c++)
	{
		if (a[c] == '-')
			continue;
		res = isdigit(a[c]);
		if (res == 0)
			break;
	}
	if (res == 0)
	{

		dprintf(STDOUT_FILENO, "L%d: usage: push integer\n", n);
		free(tmp);
		exit(EXIT_FAILURE);
	}

	if (tmp == NULL)
	{
		return;
	}

	tmp->n = strtol(a, &b, 10);

	tmp->prev = NULL;
	if (*head == NULL)
		tmp->next = NULL;
	else
	{
		tmp->next = *head;
		(*head)->prev = tmp;
	}
	*head = tmp;
	return;
}
