#include "monty.h"

/**
 * add_node - add a newnode at beginning of our
 * linked-listed behavior stack
 * @stack: double pointer to head of stack
 * @n: new data to fill in new node
 * Return: pointer to new node
 */
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
/**
 * check_digit - check if the string contains only digits
 * @arg: pointer on argument to check
 * Return: 0 if only digits are found, 1 otherwise
 */

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
/**
* _isdigit -  prints if the character is a digit.
* @c: character to check.
* Return: 0 if exited correctly, non-zero otherwise.
*/

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
