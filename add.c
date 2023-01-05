#include "monty.h"

stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *stack;
	new->prev = NULL;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
	return (new);
}

int check_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (_isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
