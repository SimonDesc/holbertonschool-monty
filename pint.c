#include "monty.h"

/**
 * pint- The function "pint" prints the value at the top of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number is an unsigned integer parameter that
 * represents the line number
 * in the script where the "pint" function is called. It is used for
 * error handling and reporting the line number in case of an error.
 */
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
