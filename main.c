#include "monty.h"

int error = 0;
/**
 * main - opens monty file and reads lines
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 success, 1 failure
 */

int main(int argc, char **argv)
{
	FILE *fd;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char str = NULL;
	char *token = NULL;
	size_t len = 1024;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(str, len, fd) != NULL && error != 1)
	{
		line_number++;
		token = strtok(str, "\n\t ");
		if (token != NULL)
		{
			get_func(token, &stack, line_number);
		}
	}
	free_stack(stack);
	free(fd);

	if (error == 1)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
