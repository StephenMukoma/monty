#include "monty.h"
/**
*str_cmp - compare 2 strings
*
*@str1: string 1
*@str2: string 2
*
*Return: 0 if same
*/
int str_cmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (str1[i]- str2[i]);
}
