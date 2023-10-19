#include "monty.h"

/**
 * main - Entry point for Monty Bytecode Interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Description: This program reads and interprets Monty bytecode files.
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	int value;
	char *filename;
	FILE *file;
	stack_t *stack = NULL;  /* Initialize an empty stack */
	char line[100];
	unsigned int line_number = 0;
	char *opcode;
	char *arg;
	stack_t *temp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
		{
			continue;  /* Empty line */
		}

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");

			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);

			push(&stack, line_number, value);  /* Updated push function */
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);  /* Updated pall function */
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);  /* Updated pint function */
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);  /* Implement pop function */
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);  /* Implement swap function */
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);  /* Implement add function */
		}
		else if (strcmp(opcode, "sub") == 0)
		{
			sub(&stack, line_number);  /* Implement sub function */
			continue;
		}
		else if (strcmp(opcode, "div") == 0)
		{
			divide(&stack, line_number);  /* Call the div function */
			continue;
		}
		else if (strcmp(opcode, "mul") == 0)
		{
			mul(&stack, line_number);  /* Call the mul function */
			continue;
		}
		else if (strcmp(opcode, "mod") == 0)
		{
			mod(&stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number);  /* Implement nop function */
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	/* Free allocated memory for the stack before exiting */
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}

	fclose(file);
	return (0);
}
