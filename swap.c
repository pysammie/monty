#include "monty.h"

/**
 * swap - swaps the top 2 element in the stack
 *
 * @head: pointer to head of stacked list
 * @counter: line number
 */
void swap(stack_t **head, unsigned int counter)
{
	stack_t *s;
	int temp, count = 0;

	s = *head;
	while (s)
	{
		s = s->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}

	s = *head;
	temp = s->n;
	s->n = s->next->n;
	s->next->n = temp;
}
