#include "monty.h"

/**
 * _mod = computes remainder of division of top element by 
 * second top element
 *
 * @head: pointer to head of stacked list
 * @counter: line number
 */
void _mod(stack_t **head, unsigned int counter)
{
	stack_t *s;
	int a, b, rem, count = 0;

	s = *head;
	while (s)
	{
		s = s->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}

	s = *head;
	a = s->n;
	b = s->next->n;

	if (a == 0)
	{
		fprintf(stderr, "L%u: division ny zero\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	rem = b % a;
	s->next->n = rem;
	*head = s->next;
	free(s);
}
