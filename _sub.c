#include "monty.h"

/**
 * _sub - sub top two nodes ad set to ndex 0
 * @head: head
 * @n: line number
 * Return: Void
 */
void _sub(stack_t **head, unsigned int n)
{
	stack_t *zero = NULL, *one = NULL;
	int sub;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	zero = get_dnodeint_at_index(*head, 0);
	one = get_dnodeint_at_index(*head, 1);
	sub = one->n - zero->n;

	delete_dnodeint_at_index(head, 0);
	delete_dnodeint_at_index(head, 0);
	add_dnodeinttop(head, sub);
}
