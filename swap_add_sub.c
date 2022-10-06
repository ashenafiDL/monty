#include "monty.h"

/**
 * swap - swaps the top two elements of stack
 * @stack: the stack
 * @line_number: line nuber of the instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int temp;

	top = *stack;
	if (top->prev == NULL || top == NULL)
	{
		fprintf(stderr,
			"L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp = top->n;
	top->n = top->prev->n;
	top->prev->n = temp;
}

/**
 * add - adds the top two elements and push the result
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int sum = 0;

	top = *stack;
	if (top->prev == NULL || top == NULL)
	{
		fprintf(stderr,
			"L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	sum += top->n;
	top = top->prev;
	pop(stack, line_number);
	sum += top->n;
	top->n = sum;
}

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack
 *
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int diff;

	top = *stack;
	if (top->prev == NULL || top == NULL)
	{
		fprintf(stderr,
			"L%d: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	diff = top->prev->n;
	diff -= top->n;
	top = top->prev;
	top->n = diff;
	pop(stack, line_number);
}
