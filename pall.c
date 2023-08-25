#include "monty.h"

/**
 * pall - prints entire stack
 *
 * @head: points to head of stacked list
 * @n: elements in stack
 */
void pall(stack_t **head, unsigned int counter)
{
	stack_t *list;
	(void)counter;

	list = *head;
	if (list == NULL)
		return;

	while(list)
	{
		printf("%d\n", list -> n);
		list = list -> next;
	}
}
