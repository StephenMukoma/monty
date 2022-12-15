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
/**
*rotr - moves bottom element to the top
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (*stack && (*stack)->next)
	{
		while (current->next)
			current = current->next;

		current->prev->next = NULL;
		current->prev = NULL;
		current->next = *stack;
		(*stack)->prev = current;
		(*stack) = current;
	}
}
