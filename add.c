#include "monty.h"

/**
 * add - The function adds the top two elements of
 * a stack and replaces them with their sum.
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: The line number is an unsigned integer
 * that represents the line number in the script where
 * the "add" function is called. It is used for error handling
 * and reporting the line number in case of an error.
 */
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
