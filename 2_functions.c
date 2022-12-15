#include "monty.h"
/**
*add - adds the top two elements of the stack
*
*@stack: pointer to list
*@line_number: line to be executed
*/
void add(stack_t **stack, unsigned int line_number)
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
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = temp + (*stack)->n;
	}
	else
	{
		fprintf(stderr, "L%u: cant add, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
/**
*sub - substracts the top element of the stack from secondto element
*
*@stack: pointer to list
*@line_number: line to be executed
*/
void sub(stack_t **stack, unsigned int line_number)
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
			fprintf(stderr, "L%u: sub, stack too short\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = (*stack)->n - temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
/**
*_div - divides top two element
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void _div(stack_t **stack, unsigned int line_number)
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
			fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = (*stack)->n / temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
