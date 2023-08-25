#include "monty.h"

/**
 * add - adds the top 2 element of a stack
 *
 * @head: pointer to head of stacked list
 * @counter: line number
 */
void add(stack_t **head, unsigned int counter)
{
	stack_t *s;
	int a, b, sum, count = 0;

	s = *head;
	while (s)
	{
		s = s->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}

	s = *head;
	a = s->n;
	b = s->next->n;
	sum = a + b;
	s->next->n = sum;
	*head = s->next;
	free(s);
}



