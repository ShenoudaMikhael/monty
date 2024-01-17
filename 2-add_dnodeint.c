#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"
/**
 * add_dnodeint - add node at the begining
 * @head: dlist
 * @n: number
 * Return: address or Null
 */
void add_dnodeint(stack_t **head, unsigned int n)
{

	stack_t *tmp = malloc(sizeof(stack_t));

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
