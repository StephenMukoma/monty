#include "monty.h"
/**
*_free - frees a list
*
*@stack: pointer to list
*/
void _free(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
}
/**
*clear - frees list and closes file
*
*@stack: pointer to list
*/
void clear(stack_t **stack)
{
	_free(stack);
	fclose(global.fd);
}
