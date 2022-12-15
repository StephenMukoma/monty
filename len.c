#include "monty.h"
/**
*len - returns number of elements in an array
*
*@c: array
*
*Return: number of elements
*/
int len(char **c)
{
	int i = 0;

	while (c[i])
	{
		i++;
	}
	return (i);
}
