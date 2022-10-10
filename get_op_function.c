#include "monty.h"

/**
 * get_op_func - handles the opcodes and their implementation functions
 * @stack: the stack
 * @op: the opcode
 * @line_number: line number of the instruction
 */
void get_op_func(stack_t **stack, char *op, unsigned int line_number)
{
	unsigned long int i;

	instructions_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr}};

	if (strcmp(op, "queue") == 0)
	{
		mode.queue = 1;
		return;
	}
	else if (strcmp(op, "stack") == 0)
	{
		mode.queue = 0;
		return;
	}
	for (i = 0; i < sizeof(instructions) / sizeof(instructions_t); i++)
	{
		if (strcmp(instructions[i].opcode, op) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
