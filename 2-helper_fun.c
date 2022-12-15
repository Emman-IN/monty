#include "monty.h"

int is_digit(char *var)
{
	int i;
	for (i = 0; var[i]; i++)
	{
		if (var[i] == '-' && i == 0)
			continue;
		if (var[i] < '0' || var[i] == 0)
		{
			return (0);
		}
	}
	return (1);
}

stack_t *add_new_node(int num)
{
	stack_t *new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	new->n = num;
	new->next = new->prev = NULL;
	return (new);
}

