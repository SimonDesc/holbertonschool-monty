#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	int a, b;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	stack_t *first = *stack;
	stack_t *second = first->next;

	a = first->n;
	b = second->n;
	second->n = a + b;
	*stack = second;
	free(first);
}
