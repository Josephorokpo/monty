#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file (unused).
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = top->next;

	second->n -= top->n;

	*stack = second;
	second->prev = NULL;
	free(top);
}
