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