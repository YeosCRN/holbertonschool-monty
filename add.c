#include "monty.h"

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
    {
		fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
	new->prev = NULL;
	new->n = n;
	if (head && *head)
	{
		(*head)->prev = new;
		new->next = (*head);
	}
	else
		new->next = NULL;
	(*head) = new;
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
