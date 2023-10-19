#include "monty.h"

/**
 * pall - Prints all values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("Printing values at line %u:\n", line_number);
		printf("%d\n", current->n);
		current = current->next;
	}
}
