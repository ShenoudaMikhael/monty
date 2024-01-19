#include "monty.h"
/**
 * _rotl - rotates the stack to the top rev
 * @head: head
 * @n: line number
 * Return: Void
 */
void _rotl(stack_t **head, unsigned int n)
{
	stack_t *tmp;

	(void)n;

	if (*head == NULL)
		return;

	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	add_dnodeint_end(head, (*head)->n);
	delete_dnodeint_at_index(head, 0);
}
