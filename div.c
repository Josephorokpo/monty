#include "monty.h"

/**
 * div - Divides the second top element of the stack by the top element.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file (unused).
 */
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int top_value = 0;
	int second_top_value = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_value = (*stack)->n;
	second_top_value = (*stack)->next->n;

	if (top_value == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second_top_value /= top_value;

	(*stack)->next->n = second_top_value;

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}
