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


/**
 * is_empty - Checks if a string is empty or contains only whitespace
 * @str: The string to check
 *
 * Return: 1 if the string is empty or contains only whitespace, 0 otherwise
 */
int is_empty(const char *str)
{
	while (*str != '\0')
	{
		if (!isspace(*str))
			return (0);
		str++;
	}
	return (1);
}


