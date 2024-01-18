#include "monty.h"
/**
 * get_dnodeint_at_index - get node at index
 * @head: list head
 * @index: list index
 * Return: node or null
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
    unsigned int i = 0;

    if (head == NULL)
        return (NULL);

    while (head != NULL)
    {
        if (i == index)
            return (head);

        head = head->next;
        i++;
    }
    return (NULL);
}

/**
 * add_dnodeinttop - add node at the begining
 * @head: dlist
 * @n: number
 * Return: address or Null
 */
stack_t *add_dnodeinttop(stack_t **head, const int n)
{

    stack_t *tmp = malloc(sizeof(stack_t));

    if (tmp == NULL)
    {
        return (NULL);
    }
    tmp->n = n;

    tmp->prev = NULL;
    tmp->next = *head;
    if (*head != NULL)
        (*head)->prev = tmp;

    *head = tmp;
    return (tmp);
}

void _add(stack_t **head, unsigned int n)
{
    stack_t *zero = NULL, *one = NULL;
    int sum;

    if (*head == NULL || (*head)->next == NULL)
    {
        dprintf(STDERR_FILENO, "L%d:  can't add, stack too short\n", n);
        exit(EXIT_FAILURE);
    }
    zero = get_dnodeint_at_index(*head, 0);
    one = get_dnodeint_at_index(*head, 1);
    sum = zero->n + one->n;

    delete_dnodeint_at_index(head, 0);
    delete_dnodeint_at_index(head, 0);
    add_dnodeinttop(head, sum);
}
