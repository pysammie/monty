#include "monty.h"

/**
 * pint - prints top element in stack
 *
 * @head: pointer to top of stacked list
 * @counter: line number
 */
void pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
