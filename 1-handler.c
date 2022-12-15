#include "monty.h"
err global;
void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	stack_t *temp;
	int num;

	if (!global.tok_num || is_digit(global.tok_num))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		global.err_stat = EXIT_FAILURE;
		return;
	}

	num = atoi(global.tok_num);
	new = add_new_node(num);
	if (check_mode(*stack) == STACK)
	{
		temp = (*stack)->next;
		new->prev = *stack;
		new->next = temp;
		if (temp)
		{
			temp->prev = new;
		}
		(*stack)->next = new;
	}
	else
	{
		temp = *stack;
		while (temp->next)
		{
			temp = temp->next;
		}
		new->prev = temp;
		new->next = NULL;
		temp->next = new;
	}
}

void pall_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	temp = (*stack)->next;
	(void)line_number;
	while (temp)
	{
		printf("%d", temp->next);
		temp = temp->next;
	}
}
