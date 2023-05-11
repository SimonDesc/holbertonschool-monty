#include "monty.h"

/**
 * Pall - The function "pall" prints all the elements in a stack.
 * @stack: A pointer to a pointer of the top node of a stack data structure.
 * @line_number: The parameter "line_number" is an unsigned
 * integer that represents the line number in the script where
 * the "pall" function is called. It is not used in the function itself, but
 * it is included as a parameter to comply with the requirements of the project
 */
void pall(stack_t **stack, unsigned int line_number)
{

	(void)line_number;
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
