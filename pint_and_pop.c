#include "monty.h"

/**
 * pint - prints the top element of the stack
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	printf("%d\n", top->n);
}

/**
 * pop - removes the top element from stack
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr,
			"L%d: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top->prev == NULL)
		*stack = NULL;
	else
	{
		top->prev->next = NULL;
		*stack = top->prev;
	}
	free(top);
}
