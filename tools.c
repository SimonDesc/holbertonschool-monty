#include "monty.h"

void remove_newline(char *str)
{
	char *newline = strchr(str, '\n');
	if (newline)
	{
		*newline = '\0';
	}
}


/**
 * free_nodes - Frees memory allocated for each node in a linked list
 * @head: A pointer to the head of the linked list
 */
void free_nodes(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}



