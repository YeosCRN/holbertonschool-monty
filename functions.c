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