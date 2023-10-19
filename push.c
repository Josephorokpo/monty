#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file.
 * @value: The integer value to push onto the stack.
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed on line %u\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
