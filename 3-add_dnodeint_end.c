
#include "monty.h"
/**
 * add_dnodeint_end - add node at end
 * @head: list address
 * @n: int
 * Return: null or link adress
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = malloc(sizeof(stack_t));
	stack_t *tail = *head;

	if (tmp == NULL)
		return (NULL);

	tmp->n = n;

	if (*head == NULL)
	{
		*head = tmp;
		return (*head);
	}
	while (tail != NULL)
	{
		if (tail != NULL && (tail)->next == NULL)
		{

			tmp->next = NULL;
			if (tail != NULL)
			{
				tmp->prev = tail;

				(tail)->next = tmp;
			}
			break;
		}
		tail = (tail)->next;
	}

	return (tmp);
}
