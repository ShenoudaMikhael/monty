#include "monty.h"

/**
 * free_stack - free the stack ptr
 * @head: stack
 * Return: void
 */
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
 * @status: on exit
 * @head: list
 * Return: void
 */
void free_dlistint(int status, void *head)
{
	stack_t **stack = head;

	(void)status;
	free_stack(*stack);
}
