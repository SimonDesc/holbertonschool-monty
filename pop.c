#include "monty.h"

/**
 * pop - The function pops the top element off a stack and
 * frees the memory allocated to it.
 *
 * @stack: A double pointer to the top of the stack.
 * It points to the address of the pointer to the first node in the stack.
 * @line_number: The line number is an unsigned integer parameter that
 * represents the line number in the script where the "pop" function is called.
 * It is used to provide error messages that indicate
 * the line number where an error occurred if the stack is empty
 * and cannot be popped.
 */
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
