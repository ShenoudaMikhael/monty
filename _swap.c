#include "monty.h"
void _swap(stack_t **head, unsigned int n)
{
    stack_t *zero = NULL, *one = NULL;

    if (*head == NULL || (*head)->next == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", n);
        exit(EXIT_FAILURE);
    }
    zero = get_dnodeint_at_index(*head, 0);
    one = get_dnodeint_at_index(*head, 1);
    zero->next = one->next;
    zero->prev = one;
    one->prev = NULL;
    one->next = zero;
    *head = one;
}
