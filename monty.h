#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
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

/**
 * struct cmd_s - variables -args, file, line content
 * @val: value
 * @file: pointer to monty file
 * @content: line content
 * @format: flag change stack to queue
 * Description: carries values through the program
 */
typedef struct cmd_s
{
	char *val;
	FILE *file;
	char *content;
	int format;
}  cmd_t;
extern cmd_t cmd;

void push(stack_t **head, unsigned int);
void pall(stack_t **head, unsigned int);
int _execute(stack_t **head, char *content, FILE *file, unsigned int counter);
void _freestack(stack_t *head);
void add_stack(stack_t **head, int n);
void pint(stack_t **head, unsigned int);
void pop(stack_t **head, unsigned int);
void swap(stack_t **head, unsigned int);
void add(stack_t **head, unsigned int);
void nop(stack_t **head, unsigned int);
void sub(stack_t **head, unsigned int);
void _div(stack_t **head, unsigned int);
void _mul(stack_t **head, unsigned int);
void _mod(stack_t **head, unsigned int);
void pchar(stack_t **head, unsigned int);


#endif
