#include "monty.h"
/**
*rotl - moves top element to the bottom
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new;
	int temp = (*stack)->n;

	if (*stack && (*stack)->next)
	{
		pop(stack, line_number);

		new = malloc(sizeof(stack_t));

		new->n = temp;
		current = *stack;
		while (current->next)
			current = current->next;

		current->next = new;
		new->prev = current;
		new->next = NULL;
	}
}
