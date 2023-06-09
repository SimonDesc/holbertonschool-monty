#include "monty.h"

/**
 * read_line - The function reads a line of input,
 * identifies the corresponding instruction, and executes it with
 * the given arguments.
 *
 * @line: A string containing the instruction to be executed.
 * @nb_line: The line number of the current instruction being read.
 * @stack: A pointer to a stack data structure.
 */
void read_line(char *line, int nb_line, stack_t **stack)
{
	char *saveptr;
	char *token = NULL;
	char *value_token = NULL;
	int i = 0;
	bool found = false;
	int arg = 0;
	instruction_t instruction[] = {{"push", push}, {"pall", pall}, {"pint", pint},
	{"mul", mul}, {"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
	{"div", divi}, {"sub", sub}, {"mod", mod}, {NULL, NULL}};

	token = strtok_r(line, " ", &saveptr);

	while (instruction[i].opcode != NULL)
	{
		if (strcmp(instruction[i].opcode, token) == 0)
		{
			value_token = strtok_r(NULL, " ", &saveptr);
			if (strcmp(token, "push") == 0)
			{
				arg = checker(value_token, nb_line);
				instruction[i].f(stack, arg);
				found = true;
				break;
			}

			instruction[i].f(stack, nb_line);
			found = true;
			break;
		}
		i++;
	}
	if (found == false)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", nb_line, token);
		cleanup();
		exit(EXIT_FAILURE);
	}
}
