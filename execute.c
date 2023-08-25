#include "monty.h"

/**
 * _execute - executes the opcode
 *
 * @stack: stacked linked list
 * @content: line content
 * @file: file containing monty code
 * @counter: line counter
 *
 * Return: 0 or 1
 */
int _execute(stack_t **stack, char *content, FILE *file, unsigned int counter)
{
	instruction_t ops_t[] = {
					{"push", push},
					{"pall", pall},
					{"pint", pint},
					{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	cmd.val = strtok(NULL, " \n\t");

	while (ops_t[i].opcode && op)
	{
		if (strcmp(op, ops_t[i].opcode) == 0)
		{
			ops_t[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && ops_t[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		_freestack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
