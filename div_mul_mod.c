#include "monty.h"

/**
 * divide - divides the second top element of the stack
 * by the top element of the stack
 *
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *new;
	int quo;

	top = *stack;
	if (top == NULL || top->prev == NULL)
	{
		fprintf(stderr,
			"L%d: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quo = top->prev->n;
	quo /= top->n;
	top = top->prev;
	pop(stack, line_number);
	if (mode.queue == 1)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		new->n = quo;

		top = top->prev;
		pop(stack, line_number);
		push_queue(stack, &new);
	}
	else
		top->n = quo;
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 *
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int prod;

	top = *stack;
	if (top == NULL || top->prev == NULL)
	{
		fprintf(stderr,
			"L%d: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	prod = top->prev->n;
	prod *= top->n;
	top = top->prev;
	top->n = prod;
	pop(stack, line_number);
}

/**
 * mod - computes the rest of the division of
 * the second top element of the stack
 * by the top element of the stack
 *
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int numer, denom;
	div_t result;

	top = *stack;
	if (top == NULL || top->prev == NULL)
	{
		fprintf(stderr,
			"L%d: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	numer = top->prev->n;
	denom = top->n;
	result = div(numer, denom);
	top = top->prev;
	top->n = result.rem;
	pop(stack, line_number);
}
