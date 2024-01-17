#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

/**
 * free_dlistint - free list
 * @head: list
 * Return: void
 */
void free_dlistint(int status, void *head)
{

	stack_t **stack = (stack_t **)head;

	stack_t *current = *stack;
	stack_t *next_node;

	(void)status;


	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
