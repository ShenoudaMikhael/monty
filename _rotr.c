#include "monty.h"
/**
 * _rotr - rotates the stack to the top
 * @head: head
 * @n: line number
 * Return: Void
 */
void _rotr(stack_t **head, unsigned int n)
{
	stack_t *tmp;
	int len = 0;

	(void)n;

	if (*head == NULL)
		return;

	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	add_dnodeinttop(head, tmp->n);
	delete_dnodeint_at_index(head, len + 1);
}
