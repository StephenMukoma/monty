#include "monty.h"
/**
*push - pushes an element to the stack
*
*@stack: pointer to list
*@line_number: line to be executed
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		clear(stack);
		exit(EXIT_FAILURE);
	}

		new->n = global.element;
		new->prev = NULL;
		new->next = *stack;
		*stack = new;

	if (new->next != NULL)
		new->next->prev = new;
}
/**
*pall - prints all values on the stack
*
*@line_number: line being executed
*@stack:pointer to list
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (*stack == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
*pint - prints top element on stack
*
*@stack: pointer to list
*@line_number: line being executed
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
