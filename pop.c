#include "monty.h"

/**
 * pop - Removes the top element from the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	*stack = top_node->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(top_node);
}
