#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	stack_t *first = *stack;
	stack_t *second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
}
