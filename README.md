# 0x19. C - Stacks, Queues - LIFO, FIFO
***ALX Software Engineering Programme Project***

## Introduction

This group project involves implementing a scripting language called Monty 0.98, which is compiled into Monty byte codes. Monty relies on a unique stack with specific instructions for manipulating it. The goal of this project is to create an interpreter for Monty ByteCode files.

## Learning Objectives

- Understanding of LIFO and FIFO principles
- Knowledge of what a stack is and when to use it
- Understanding of what a queue is and when to use it
- Familiarity with common implementations of stacks and queues
- Recognition of common use cases for stacks and queues
- Proper use of global variables

## Requirements

- Allowed editors: vi, vim, emacs
- All code will be compiled on Ubuntu 20.04 LTS using gcc with the options: -Wall -Werror -Wextra -pedantic -std=c89
- All code files should end with a new line
- A README.md file in the project folder is mandatory
- Code must follow the Betty style (to be checked using betty-style.pl and betty-doc.pl)
- Maximum of one global variable is allowed
- No more than 5 functions per file
- The C standard library can be used
- Prototypes of all functions should be included in the header file named `monty.h`
- All header files should be include guarded

## Data Structures

For this project, please use the following data structures and include them in your `monty.h` header file:

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

## Compilation & Output
The code will be compiled using the following command:

$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

> All output must be printed on stdout
> Any error message must be printed on stderr

## The Monty Program

Usage: monty file where file is the path to the Monty byte code file.
If no file or more than one argument is provided, print the error message "USAGE: monty file" and exit with status EXIT_FAILURE.
If the file cannot be opened, print the error message "Error: Can't open file <file>" and exit with status EXIT_FAILURE.
If an invalid instruction is found in the file, print the error message "L<line_number>: unknown instruction <opcode>" and exit with status EXIT_FAILURE.
If malloc fails, print the error message "Error: malloc failed" and exit with status EXIT_FAILURE.
You are only allowed to use malloc and free and not other functions from the malloc family (realloc, calloc, etc.).

## Tasks

0. push, pall
Implement the push and pall opcodes.
> The push opcode pushes an element onto the stack.
> The pall opcode prints all values on the stack from top to bottom.

1. pint
Implement the pint opcode.
> The pint opcode prints the value at the top of the stack.

2. pop
Implement the pop opcode.
> The pop opcode removes the top element of the stack.

3. swap
Implement the swap opcode.
> The swap opcode swaps the top two elements of the stack.

4. add
Implement the add opcode.
> The add opcode adds the top two elements of the stack.

5. nop
Implement the nop opcode.
> The nop opcode does nothing.
