#include "monty.h"

/**
 * push - push an element to the top of the stack
 * @stack: the stack
 * @line_number: line number of the instruction_s
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	stack_t *new, *top;

	argument = strtok(NULL, " \t\n");

	if (argument == NULL || check_digit(argument) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(argument);

	if (mode.queue == 1)
	{
		push_queue(stack, &new);
		return;
	}

	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}

	top = *stack;
	top->next = new;
	new->prev = top;
	*stack = new;
}

/**
 * push_queue - push data in queue mode
 *
 * @stack: the stack/queue
 * @new: the new node
 */
void push_queue(stack_t **stack, stack_t **new)
{
	stack_t *rear;

	(*new)->prev = NULL;

	if (*stack == NULL)
	{
		(*new)->next = NULL;
		*stack = *new;
		return;
	}

	rear = *stack;
	while (rear->prev != NULL)
		rear = rear->prev;

	rear->prev = *new;
	(*new)->next = rear;
}


/**
 * pall - prints the elements of the stack from top to bottom
 * @stack: the stack
 * @line_number: line number of the instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	(void)line_number;

	if (*stack == NULL)
		return;

	top = *stack;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->prev;
	}
}
