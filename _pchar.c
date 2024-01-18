#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack
 * @head: head
 * @n: line number
 * Return: Void
*/
void _pchar(stack_t **head, unsigned int n)
{
    if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
    if ((*head)->n < 0 || (*head)->n > 127)
    {
        dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", n);
		exit(EXIT_FAILURE);
    }
    printf("%c\n", (*head)->n);
}