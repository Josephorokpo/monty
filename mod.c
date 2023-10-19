#include "monty.h"

/**
 * mod - Computes the remainder of the division of the second top element
 *       of the stack by the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n %= top->n;

	*stack = second;
	second->prev = NULL;
	free(top);
}
