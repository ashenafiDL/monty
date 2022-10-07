#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (top == NULL)
	{
		fprintf(stderr,
			"L%d: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((top->n < 65 || top->n > 90) && (top->n < 97 || top->n > 122))
	{
		fprintf(stderr,
			"L%d: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	top = *stack;
	while (top != NULL)
	{
		if ((top->n == 0) || ((top->n < 65 || top->n > 90)
				&& (top->n < 97 || top->n > 122)))
			break;

		printf("%c", top->n);
		top = top->prev;
	}
	printf("\n");
}
