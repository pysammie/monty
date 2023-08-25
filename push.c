#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @head: head of stacked linked list
 * @counter: line number
 */
void push(stack_t **head, unsigned int counter)
{
	int n, i = 0, flag = 0;

	if (cmd.val)
	{
		if (cmd.val[0] == '-')
			i++;
		while (cmd.val[i] != '\0')
		{
			if (cmd.val[i] < 48 || cmd.val[i] > 57)
				flag = 1;
			i++;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(cmd.file);
			free(cmd.content);
			_freestack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(cmd.file);
		free(cmd.content);
		_freestack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(cmd.val);
	if (cmd.format == 0)
		add_stack(head, n);
}

