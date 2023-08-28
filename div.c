#include "monty.h"

/**
 * div - divides second element by top element
 *
 * @head: pointer to head of stacked list
 * @counter: line number
 */
void _div(stack_t **head, unsigned int counter)
{
	stack_t *s;
	int a, b, res, count = 0;

	s = *head;
	while (s)
	{
		s = s->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", counter);
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
		fprintf(stderr, "L%u: division by zero\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}

	res = b / a;
	s->next->n = res;
	*head = s->next;
	free(s);
}
