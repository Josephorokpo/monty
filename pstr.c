#include <stdio.h>

/**
 * pstr - Prints a string from the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	char buffer[1024];  /* Adjust the buffer size as needed */
	int buffer_index = 0;

	while (current != NULL && current->n != 0 &&
		       (current->n >= 0 && current->n <= 127))
	{
		buffer[buffer_index++] = (char)current->n;
		current = current->next;
	}

	buffer[buffer_index] = '\0';

	if (buffer_index > 0)
	{
		printf("%s\n", buffer);
	}
	else
	{
		fprintf(stderr, "L%u: can't pstr, stack is empty or contains
			       non-printable characters\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (*stack != NULL)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
