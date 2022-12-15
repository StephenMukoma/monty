#include "monty.h"
/**
*exec_cmd - call functions to execute command
*
*@command: array containing command
*@line_number: line to be executed
*@head:pointer to list
*/
void exec_cmd(char **command, unsigned int line_number, stack_t **head)
{
	int i = 0;
	instruction_t selector[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}
		};
	if (str_cmp(command[0], "push") == 0)
	{
		if (len(command) == 2)
		{
			if (is_digit(command[1]) == 1)
				global.element = atoi(command[1]);
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				clear(head);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			clear(head);
			exit(EXIT_FAILURE);
		}
	}

	while ((selector + i)->opcode)
	{
		if (str_cmp((selector + i)->opcode, command[0]) == 0)
		{
			(selector + i)->f(head, line_number);
			return;
		}
		i++;
	}
}

