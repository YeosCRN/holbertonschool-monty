#include "monty.h"

void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *new = NULL;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = global_var;
    new->prev = NULL;

    if (*stack == NULL)
    {
        new->next = NULL;
        *stack = new;
        return;
    }
    new->next = *stack;
    (*stack)->prev = new;
    *stack = new;
}

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *temp = NULL;

    temp = *stack;
    if ((*stack) == NULL)
            return;
    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

void get_func(char *op, stack_t **stack, unsigned int line_number)
{
	instruction_t find_op[] = {
		{"push", push},
		{"pall", pall},
        {NULL, NULL}
    };
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
	printf("L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
