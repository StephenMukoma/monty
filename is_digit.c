#include "monty.h"
/**
*is_digit - checks for a digit 0 to 9
*
*@c: variable
*
*Return: 0 or 1
*/
int is_digit(char *c)
{
	char *aux = c;


	if (c == NULL)
		return (0);
	if (*aux == '-')
		aux++;

	for (; *aux != '\0'; aux++)
	{
		if ((*aux < '0' || *aux > '9'))
		{
			return (0);
		}
	}
	return (1);
}
