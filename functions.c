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
/**
*pop - remove top element
*
*@stack: pointer to list
*@line_number: line being executed
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (!curr)
	{
		fprintf(stderr, "L%u: can't pop an empty\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = curr->next;
		if (*stack)
			(*stack)->prev = NULL;
	}
	free(curr);
}
#include "monty.h"
/**
*swap - swaps top 2 elements
*
*@stack:pointer to list
*@line_number: line being executed
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int counter = 0, temp;
	stack_t *curr = *stack;

	if (curr)
	{
		while (curr)
		{
			curr = curr->next;
			counter++;
		}
		if (counter < 2)
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
