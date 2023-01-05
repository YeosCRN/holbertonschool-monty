#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    int add;
    char *value;

    value = strtok(NULL," ");
    if (value == NULL || is_number(value))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    add = atoi(value);
    if (add_node(stack, add))
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
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

    int i;

    for (i = 0; find_op[i].opcode != NULL; i++)
	{
		if (strcmp(op, find_op[i].opcode) == 0)
		{
			find_op[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);

}
