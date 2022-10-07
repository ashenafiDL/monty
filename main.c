#define  _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - entry point of the program
 * @argc: argument count
 * @argv: argument vector
 * Return: (int) always 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL; /* points to the top of the stack */
	unsigned int line_number;
	FILE *file;
	char *line = NULL, *op;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while (getline(&line, &len, file) != -1)
	{
		if (*line == '\n')
		{
			line_number++;
			continue;
		}
		printf("op = %s\n", op);
		if ((op == NULL
			|| strcmp(op, "nop") == 0)
			|| (strcmp(op, "#") == 0))
		{
			line_number++;
			continue;
		}
		get_op_func(&stack, op, line_number);
		line_number++;
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (0);
}
