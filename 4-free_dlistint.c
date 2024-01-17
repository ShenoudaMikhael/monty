#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"
/**
 * free_dlistint - free list
 * @head: list
 * Return: void
 */
void free_dlistint(int status, void *head)
{
	stack_t **stack = (stack_t **)head;
	stack_t *next;

	(void)status;

	if (*stack == NULL)
	{
		return;
	}

	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}
