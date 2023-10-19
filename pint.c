#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);

	/* Remove the top element */
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}
