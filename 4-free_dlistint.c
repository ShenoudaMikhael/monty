#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

void free_stack(stack_t *head)
{
	if (head == NULL)
	{
		return;
	}

	free_stack(head->next);

}

/**
 * free_dlistint - free list
 * @head: list
 * Return: void
 */
void free_dlistint(int status, void *head)
{
	stack_t *stack = (stack_t *)head;

	(void)status;

	free_stack(stack);
}
