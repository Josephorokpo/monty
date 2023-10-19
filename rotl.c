#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file (unused).
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *second;

	/* Debug: Printing the unused line_number parameter for debugging */
	printf("Debug: Unused line_number: %u\n", line_number);

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		second = (*stack)->next;
		while (last->next != NULL)
		{
			last = last->next;
		}
		(*stack)->next = last->next;
		last->next = *stack;
		*stack = second;
		(*stack)->prev = NULL;
	}
}
