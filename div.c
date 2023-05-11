#include "monty.h"

/**
 * divi - The function div the two top element
 * a stack and replaces them with their sum.
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: The line number is an unsigned integer
 * that represents the line number in the script where
 * the "divi" function is called. It is used for error handling
 * and reporting the line number in case of an error.
 */
void divi(stack_t **stack, unsigned int line_number)
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

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	a = second->n;
	b = first->n;
	a = b / a;
	second->n = a;
	*stack = second;
	free(first);
}
