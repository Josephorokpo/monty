#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = top->next;

	second->n *= top->n;

	*stack = second;
	second->prev = NULL;
	free(top);
}
