#include "monty.h"

/**
 * sub - subtracts the top element from the second
 * top element, stores result in the second top element
 *
 * @head: pointer to the head of stacked list
 * @counter: line number
 */
void sub(stack_t **head, unsigned int counter)
{
	stack_t *s;
	int a, b, diff, count = 0;

	s = *head;
	while (s)
	{
		s = s->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}

	s = *head;
	a = s->n;
	b = s->next->n;
	diff = b - a;
	s->next->n = diff;
	*head = s->next;
	free(s);
}
