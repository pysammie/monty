#include "monty.h"
cmd_t cmd = {NULL, NULL, NULL, 0};

/**
 * main - A monty interpreter
 *
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *content = NULL;
	FILE *file;
	size_t bufsize = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	cmd.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (readline > 0)
	{
		readline = getline(&content, &bufsize, file);
		cmd.content = content;
		counter++;
		if (readline > 0)
		{
			_execute(&stack, content, file, counter);
		}
	}
	free(content);
	_freestack(stack);
	fclose(file);

	return (0);
}
