#include "monty.h"

/**
 * _add - Function that add the two last node of a linked list data
 * @stack: Double pointer to the head of stack
 * @line_number: line number of file we process
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int res = 0;

	if (*stack && (*stack)->next)
	{
		res += (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n += res;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		error = 1;
		return;
	}
}

/**
 * _nop - stacks and lines on request
 * @stack: double pointer to head of stack
 * @line_number: line number of file we process
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * get_func - check what function to pick according to input
 * @op: opcode file to run on
 * @stack: double pointer to head of stack
 * @line_number: line number of file we process
 */
void get_func(char *op, stack_t **stack, unsigned int line_number)
{
	instruction_t find_op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
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
