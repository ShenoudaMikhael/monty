#ifndef _MONTY_H
#define _MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct gvar_s
{
    char *line;
    stack_t *stack;
} gvar_t;

extern gvar_t gvar;

void do_op(stack_t **stack, char *line, int n);
void add_dnodeint(stack_t **head, unsigned int n);
void print_dlistint(stack_t **h, unsigned int n);
void _pint(stack_t **head, unsigned int n);
void _nop(stack_t **head, unsigned int n);
void _pop(stack_t **head, unsigned int n);
void _add(stack_t **head, unsigned int n);
void _swap(stack_t **head, unsigned int n);
void _sub(stack_t **head, unsigned int n);
void _div(stack_t **head, unsigned int n);
void _mul(stack_t **head, unsigned int n);

char **strtow(char *str);
void free_stack(stack_t *head);
void free_line(int status, void *argv);
void free_dlistint(int status, void *head);

stack_t *get_mydnodeint_at_index(
    stack_t *head, unsigned int index, unsigned int *i);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
stack_t *add_dnodeinttop(stack_t **head, const int n);

int delete_dnodeint_at_index(stack_t **head, unsigned int index);

#endif