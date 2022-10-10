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
	if (top == NULL || top->prev == NULL)
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
	stack_t *top, *new;
	int sum = 0;

	top = *stack;
	if (top == NULL || top->prev == NULL)
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

	if (mode.queue == 1)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		new->n = sum;

		top = top->prev;
		pop(stack, line_number);
		push_queue(stack, &new);
	}
	else
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
	stack_t *top, *new;
	int diff;

	top = *stack;
	if (top == NULL || top->prev == NULL)
	{
		fprintf(stderr,
			"L%d: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	diff = top->prev->n;
	diff -= top->n;
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

		new->n = diff;

		top = top->prev;
		pop(stack, line_number);
		push_queue(stack, &new);
	}
	else
		top->n = diff;
}
