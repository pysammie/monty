#include "monty.h"

/**
 * add_stack - adds element to top of stack
 *
 * @head: pointer to top of stacked list
 * @n: element to be added
 */
void add_stack(stack_t **head, int n)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));

	temp = *head;
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (temp)
		temp->prev = new;

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	*head = new;
}
