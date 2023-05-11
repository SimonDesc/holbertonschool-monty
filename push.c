#include "monty.h"
/**
 * push - "push" adds a new node to the top of a stack data structure.
 * @stack: a double pointer to the top of the stack, which is
 * a linked list of stack_t nodes.
 * @line_number: The line number is an unsigned integer that
 * represents the line number in the script where the "push" command is called.
 * It is used to assign a value to the "n" member of the new
 * node that is being added to the stack.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		cleanup();
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
