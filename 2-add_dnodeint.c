#include "monty.h"
/**
 * add_dnodeint - add node at the begining
 * @head: dlist
 * @n: number
 * Return: Void
 */
void add_dnodeint(stack_t **head, unsigned int n)
{
	size_t c = 0;
	stack_t *tmp = NULL;
	char *a = NULL;

	a = strtok(NULL, "\n\t\r ");
	if (a == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}
	for (c = 0; c < strlen(a); c++)
	{
		if (a[c] == '-' && c == 0)
			continue;
		if (isdigit(a[c]) == 0)
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}
	}
	if (is.stack == 1)
	{
		tmp = malloc(sizeof(stack_t));
		if (tmp == NULL)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n"), exit(EXIT_FAILURE);
		}
		tmp->n = atoi(a);
		tmp->prev = NULL;
		if (*head == NULL)
			tmp->next = NULL;
		else
			tmp->next = *head, (*head)->prev = tmp;
		*head = tmp;
	}
	else
	{
		free(tmp);
		add_dnodeint_end(head, atoi(a));
	}
}
