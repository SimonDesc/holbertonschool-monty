#include "monty.h"

int checker(char *value_token, int nb_line)
{
	int i = 0;

	if (value_token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", nb_line);
		cleanup();
		exit(EXIT_FAILURE);
	}

	for (i = 0; value_token[i] != '\0'; i++)
	{
		if (value_token[i] == '-')
		{
			i++;
		}

		if (isdigit(value_token[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", nb_line);
			cleanup();
			exit(EXIT_FAILURE);
		}
	}
	return (atoi(value_token));
}
