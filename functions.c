#include "monty.h"

/**
 * push_func - pushes an element to the stack
 * @stack: double pointer to a double linked list as stack
 * @line_number: number of lines inside the opcode file
 * Return: void
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *push_element;
	(void) line_number;

	push_element = malloc(sizeof(stack_t));
	if (push_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	push_element->n = global_var;
	if (*stack == NULL)
		push_element->next = NULL;
	else
		push_element->next = *stack;
	push_element->prev = NULL;
	*stack = push_element;
	if (push_element->next != NULL)
		push_element->next->prev = push_element;

}

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

void get_func(char *op, stack_t **stack, unsigned int line_number)
{
	instruction_t find_op[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}};

	int index = 0;

	while (find_op[index].opcode != NULL)
	{
		if (strcmp(find_op[index].opcode, op) == 0)
		{
			find_op[index].f(stack, line_number);
			return;
		}
		index++;
	}
	printf("L%u: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
