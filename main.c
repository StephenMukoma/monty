#include "monty.h"
glob_t global;
/**
*main
*
*@argc: number of arguments
*@argv: argument vector
*
*Return: 0
*/

int main(int argc, char *argv[])
{
	FILE *file;
	char lineptr[1024];
	size_t n = 1024;
	unsigned int line_number = 1;
	stack_t *head = NULL;
	char **cmd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(lineptr, n, file) != NULL)
	{
		cmd = parser(lineptr);
		if (str_cmp(cmd[0], "#") == 0)
			continue;
		if (check_line(cmd) == -1)
		{
			fprintf(stderr,"L%u: unknown instruction %s\n", line_number, cmd[0]);
			exit(EXIT_FAILURE);
		}
		exec_cmd(cmd, line_number, &head);
		line_number++;
	}
	free(cmd);
	fclose(file);
	return(0);
}
/**
*parser- tokenize command
*
*@buffer: string with command
*
*Return: tokenized command
*/
char **parser(char *buffer)
{
	char **command, *token;
	int i;

	if (buffer == NULL)
	{
		return (NULL);
	}

	token = strtok(buffer, " \t\n\r");
	if (token == NULL)
	{
		return (NULL);
	}

	command = malloc(sizeof(char *) *1024);

	i = 0;
	while (token)
	{
		command[i++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	command[i] = NULL;
	return (command);
}
