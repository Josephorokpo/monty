#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	/* Calculate the sum and store it in the second element */
	second->n += top->n;

	/* Remove the top element */
	*stack = second;
	if (second->next != NULL)
	{
		second->next->prev = second;
	}

	free(top);
}
