#include "monty.h"

FILE *global_stream = NULL;
stack_t *global_stack = NULL;


int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int nb_line = 1;
	stack_t *stack = NULL;
	

	if (argc < 2)
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
			read_line(line, nb_line, &stack);
			nb_line++;
			global_stack = stack;
		}
		free(line);
	}
	cleanup();
	return (0);
}


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







