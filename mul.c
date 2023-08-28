#include "monty.h"

/**
 * _mul - multiplies the second element with the top element
 *
 * @head: pointer to head of stacked list
 * @counter: line number
 */
void _mul(stack_t **head, unsigned int counter)
{
	stack_t *s;
	int a, b, prod, count = 0;

	s = *head;
	while (s)
	{
		s = s->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}

	s = *head;
	a = s->n;
	b = s->next->n;

	prod = a * b;
	s->next->n = prod;
	*head = s->next;
	free(s);
}
