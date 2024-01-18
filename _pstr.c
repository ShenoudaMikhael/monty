#include "monty.h"
/**
 * _pstr - prints the char at the top of the stack
 * @head: head
 * @n: line number
 * Return: Void
 */
void _pstr(stack_t **head, unsigned int n)
{
    stack_t *tmp = *head;

    (void)n;

    while (tmp != NULL)
    {
        if ((tmp->n >= 65 && tmp->n <= 90) || (tmp->n >= 97 && tmp->n <= 122))
        {
            printf("%c", tmp->n);
        }
        else
        {
            break;
        }
        tmp = tmp->next;
    }
    printf("\n");
}
