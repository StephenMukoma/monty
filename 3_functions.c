#include "monty.h"
/**
*mod - gets modulus of top two element
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (*stack)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
		(*stack)->n = (*stack)->n % temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
/**
*pchar - prints ascii value of top element
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack && stack)
	{
		if ((*stack)->n > 127 || (*stack)->n < 0)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		putchar((*stack)->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
