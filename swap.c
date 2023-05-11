#include "monty.h"

/**
 * Swap - The function swaps the positions of the top two elements in a stack.
 * 
 * @stack: A double pointer to the top of the stack, which is a linked list of integers.
 * @line_number: The line number is an integer value that 
 * represents the line number in the script
 * where the "swap" function is called. It is used for error handling
 * and reporting the line number in case of an error.
 */
void swap(stack_t **stack, unsigned int line_number)
{	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		cleanup();
		exit(EXIT_FAILURE);
	}

	stack_t *first = *stack;
	stack_t *second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
}
