
#include "monty.h"

int main(void)
{
	/* ouvrir le fichier */
	FILE *stream = NULL;

	/* stocker la valeur de notre ligne */
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int nb_line = 1;

	stream = fopen("bytecodes/00.m", "r");

	if (stream != NULL)
	{
		while ((nread = getline(&line, &len, stream)) != -1)
		{
			remove_newline(line);
			read_line(line, nb_line);
			nb_line++;
		}
	}

	else
	{
		printf("Impossible d'ouvrir le fichier");
	}

	fclose(stream);
	return (0);
}

void read_line(char *line, int nb_line)
{
	char *saveptr;
	char *token = NULL;
	int i = 0;
	stack_t *stack = NULL;

	instruction_t instruction[] = {
	    {"push", push},
	    {"pall", pall},
	    {NULL, NULL}};

	token = strtok_r(line, " ", &saveptr);
	char *value_token = strtok_r(NULL, " ", &saveptr);
	if (value_token != NULL)
	{
		global_value = atoi(value_token);
	}
	
	while (instruction[i].opcode != NULL)
	{
		if (strcmp(instruction[i].opcode, token) == 0)
		{
			instruction[i].f(&stack, nb_line);
		}
		i++;
	}
}

void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	int value = global_value;

	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Erreur d'allocation de mémoire\n");
		return;
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
	printf("Element ajouté à la pile : %d\n", value);
}

void pall(stack_t **stack, unsigned int line_number)
{

	(void)line_number;
	stack_t *current = *stack;
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

void remove_newline(char *str)
{
	char *newline = strchr(str, '\n');
	if (newline)
	{
		*newline = '\0';
	}
}
/*
The push opcode

The opcode push pushes an element to the stack.

    Usage: push <int>
	where <int> is an integer
    if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
	where is the line number in the file
    You won’t have to deal with overflows. Use the atoi function

The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the stack.

    Usage pall
    Format: see example
    If the stack is empty, don’t print anything

julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$

*/
