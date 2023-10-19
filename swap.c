#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	/* Adjust the stack pointers */
	top->prev = second;
	top->next = second->next;
	second->prev = NULL;
	second->next = top;

	*stack = second;
}
