
#include "monty.h"
/**
 * get_dnodeint_at_index - get node at index
 * @head: list head
 * @index: list index
 * @i: current index
 * Return: node or null
 */
stack_t *get_mydnodeint_at_index(
	stack_t *head, unsigned int index, unsigned int *i)
{
	if (head == NULL)
		return (NULL);

	while (head != NULL)
	{
		if (*i == index)
		{

			return (head);
		}

		head = head->next;
		*i = *i + 1;
	}
	return (NULL);
}

/**
 * delete_dnodeint_at_index - delete at index
 * @head: list
 * @index: index
 * Return: int
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int i = 0;
	stack_t *tmp = NULL;

	if (head == NULL || *head == NULL)
		return (-1);
	tmp = get_mydnodeint_at_index(*head, index, &i);
	if (index == 0 && *head)
	{

		if ((*head)->next)
		{
			*head = (*head)->next;
			(*head)->prev = NULL;
		}
		else
			*head = NULL;
		free(tmp);
		return (1);
	}
	else if (i == index)
	{
		if (tmp->next)
			tmp->next->prev = tmp->prev;

		tmp->prev->next = tmp->next;
		free(tmp);
		return (1);
	}

	return (-1);
}
/**
 * _pop - remove top item
 * @head: list
 * @n: line number
 * Return: void
*/
void _pop(stack_t **head, unsigned int n)
{
	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(head, 0);
}
