#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{	
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	stack_t *current = *stack;

	printf("%d\n", current->n);

}
