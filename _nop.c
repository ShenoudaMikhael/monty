#include "monty.h"
/**
 * _nop - no operation
 * @head: list
 * @n: line number
 * Return: Void
 */
void _nop(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
	while (strtok(NULL, "\n\t\r "))
		;
}
