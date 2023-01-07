#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to a double linked list as stack
 * @line_number: number of lines inside the opcode file
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int add;
	char *value;

	value = strtok(NULL, "\n\t ");
	if (value == NULL || check_digit(value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add = atoi(value);
	if (add_node(stack, add) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall- prints all the values of the stack starting from the top
 * @stack: double pointer to a double linked list as stack
 * @line_number: number of lines inside the opcode file
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		if (temp == *stack)
		{
			return;
		}
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: double pointer to the beggining of the stack (DLL)
 * @line_number: the numbers of lines in the opcode file
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pop - function that removes the top element of stack
 * @stack: double pointer to head of stack
 * @line_number: line number of file we process on
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		error = 1;
		return;
	}
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 *_swap - swaps the top two elements of stack
 *@stack: double pointer to head of stack
 *@line_number: line number of file we process on
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int swapper;

	if (*stack && (*stack)->next)
	{
		swapper = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = swapper;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		error = 1;
		return;
	}
}
