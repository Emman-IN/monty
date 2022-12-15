#include "monty.h"

/**
 * stack_init-initialize an empty stack
 * Return: pointer to new stack
 */

stack_t *stack_init(void)
{
	stack_t *new;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = STACK;
	new->next = new->prev = NULL;
	return (new);
}

void (*get_op_func(char *ops))(stack_t **, unsigned int)
{
	int i;
	instruction_t func[] =
	{
		{"push", push_handler},
		{"pall", pall_handler},
		{NULL, NULL}};
	for (i = 0; func[i].opcode; i++)
	{
		if (strcmp(func[i].opcode, ops) == 0)
		{
			return (func[i].f);
		}
	}
	return (NULL);
}

int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
