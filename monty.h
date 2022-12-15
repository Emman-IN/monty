#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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

/**
 * struct error - error handling struct
 * @err_stat: holds error value
 * @tok_num: tokenized number from line read
 */
typedef struct error
{
	int err_stat;
	char *tok_num;
} err;

#define STACK 1
#define QUEUE 0
#define FAILURE -1
#define DELIM " \n\t\r\a\b"

void push_handler(stack_t **stack, unsigned int line_number);

#endif // MONTY
