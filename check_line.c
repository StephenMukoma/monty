#include "monty.h"
/**
*check_line - check if command exist
*
*@command: array of commands
*
*Return: 0 if true else -1
*/
int check_line(char **cmd)
{
	int i = 0;
	char *array[] = {"push", "pall", "pint", "pop", "swap", "add","sub", "div", "mod", NULL};

	while(array[i] != NULL)
	{
		if (str_cmp(array[i], cmd[0]) == 0)
			return (0);
		i++;
	}
	return (-1);
}
