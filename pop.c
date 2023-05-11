#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{	
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	stack_t *current = *stack;
	stack_t *next = NULL;

	next = current->next;
	free(current);
	*stack = next;
}
