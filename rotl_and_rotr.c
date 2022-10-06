#include "main.h"

/**
 * rotl - rotates the stack to the top
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *top;

	(void)line_number;

	bottom = *stack;
	top = *stack;
	if (*stack == NULL || top->prev == NULL)
		exit(EXIT_SUCCESS);

	while (bottom->prev != NULL)
		bottom = bottom->prev;

	top->prev->next = NULL;
	*stack = top->prev;

	top->prev = NULL;
	top->next = bottom;
	bottom->prev = top;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: the stack
 * @line_number: line nuber of the instruction
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;

	top = *stack;
	bottom = *stack;
	if (top == NULL || top->prev == NULL)
		exit(EXIT_SUCCESS);

	while (bottom->prev != NULL)
		bottom = bottom->prev;

	*stack = bottom;
	top->next = bottom;
	bottom->next->prev = NULL;
	bottom->next = NULL;
	bottom->prev = top;
}
