#include "monty.h"

/**
 * Pop - The function does nothing and takes in a stack
 *  and line number as parameters.
 * @stack: The stack parameter is a pointer to a pointer
 * to the top of the stack. It is used to access and manipulate
 * the stack data structure. In this particular function, the stack parameter
 * is not used, so it is cast to void to avoid a compiler
 * warning about an unused parameter.
 * @line_number: The line number is an unsigned integer
 * that represents the line number in the
 * script where the current instruction is located.
 * It is used for error handling and reporting
 * purposes. In this case, the `nop` function does
 * not use the `line_number` parameter, so it is cast to `void` to
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
