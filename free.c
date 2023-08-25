#include "monty.h"

/**
 * _freestack - frees stacked list
 *
 * @head: head pointer of stacked list
 */
void _freestack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

