#include "monty.h"

/**
 * pop - removes top element from stack
 *
 * @head: pointer to head of stacked list
 * @counter: line number
 */
void pop(stack_t **head, unsigned int counter)
{
	stack_t *old;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	old = *head;
	*head = old->next;
	free(old);
}
