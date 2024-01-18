#include "monty.h"
/**
 * _pstr - prints the char at the top of the stack
 * @head: head
 * @n: line number
 * Return: Void
 */
void _pstr(stack_t **head, unsigned int n)
{
    (void)n;
    if (head == NULL)
    {
        printf("\n");
    }
    while (*head != NULL)
    {
        if ((*head) == NULL || (*head)->n == 0 || ((*head)->n < 0 || (*head)->n > 127))
            break;
        else
        {
            printf("%c", (*head)->n);
            (*head) = (*head)->next;
        }
    }
    printf("\n");
}
