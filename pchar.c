#include "monty.h"

/**
 * pchar - prints char at top of stack
 *
 * @head: pointer to head of stacked list
 * @counter: line number
 */
void pchar(stack_t **head, unsigned int counter)
{
	stack_t *s;
	int a;

	s = *head;
	if (s == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}

	a = s->n;
	if (a < 0 || a > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", a);
}
