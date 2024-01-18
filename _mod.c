#include "monty.h"

/**
 * _mod - mod top two nodes ad set to ndex 0
 * @head: head
 * @n: line number
 * Return: Void
 */
void _mod(stack_t **head, unsigned int n)
{
	stack_t *zero = NULL, *one = NULL;
	int mod;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", n);
		exit(EXIT_FAILURE);
	}
	zero = get_dnodeint_at_index(*head, 0);
	one = get_dnodeint_at_index(*head, 1);
	mod = one->n % zero->n;

	delete_dnodeint_at_index(head, 0);
	delete_dnodeint_at_index(head, 0);
	add_dnodeinttop(head, mod);
}
