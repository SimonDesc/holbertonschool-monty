#include "monty.h"

/**
 *  checker - The function checks if a given string is a valid integer
 *  and returns its integer value.
 * @value_token: A pointer to a string representing a token
 * that should contain an integer value.
 * @nb_line: is an integer variable that represents
 * the line number in the input file where the current command is located.
 * It is used to provide more informative error messages in case
 * of syntax errors or other issues.
 * Return: an integer value, which is the converted value of the input string
 * (value_token) after checking if it is a valid integer.
 */
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
