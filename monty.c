#include "monty.h"

/* flag for queue and stack length */
var_t var;

/**
 * main - Interpreter monty bytecode files.
 *
 * @argc: Number of arguments
 * @argv: List of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *fs = NULL;
	char *line_ptr = NULL, *op = NULL;
	size_t n = 0;

	var.queue = 0;
	var.stack_len = 0;

	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fs = fopen(argv[1], "r");

	if (fs == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	on_exit(free_line_ptr, &line_ptr);
	on_exit(free_stack, &stack);
	on_exit(fs_close, fs);

	while (getline(&line_ptr, &n, fs) != -1)
	{
		line_number++;
		op = strtok(line_ptr, "\n\t\r ");

		if (op != NULL && op[0] != '#')
		{
			get_operation(op, &stack, line_number);
		}
	}

	exit(EXIT_SUCCESS);
}
