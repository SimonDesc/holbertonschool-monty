#include "monty.h"

FILE *global_stream = NULL;
stack_t *global_stack = NULL;

/**
 * main - This function reads a file line by line, removes newlines,
 * checks if the line is empty, and then
 * reads the line and executes the corresponding command.
 *
 * @argc: The number of arguments passed to the program, including
 * the name of the program itself.
 * @argv: argv is a pointer to an array of characters that
 * represent the command-line arguments
 * passed to the program. In this specific code,
 * it is used to pass the name of the file to be opened
 * and read.
 * Return: an integer value of 0.
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int nb_line = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global_stream = fopen(argv[1], "r");
	if (global_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		while ((nread = getline(&line, &len, global_stream)) != -1)
		{
			remove_newline(line);
			if (is_empty(line) == 0)
			{
				read_line(line, nb_line, &stack);
			}
			nb_line++;
			global_stack = stack;
		}
		free(line);
	}
	cleanup();
	return (0);
}

/**
 * cleanup - The function "cleanup" closes a file
 * stream and frees memory allocated for a stack.
 */
void cleanup(void)
{

	if (global_stream != NULL)
	{
		fclose(global_stream);
		global_stream = NULL;
	}

	if (global_stack != NULL)
	{
		free_nodes(global_stack);
		global_stack = NULL;
	}
}
