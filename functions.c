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
 * get_func- check what function to pick according to input
 * @op: opcode file to run on
 * @stack: double pointer to head of stack
 * @line_number: line number of file we process
 */
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
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}

#include "monty.h"
/**
 * pint_func - prints the value at the top of the stack
 * @stack: double pointer to the beggining of the stack (DLL)
 * @line_number: the numbers of lines in the opcode file
 * Return: void
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}