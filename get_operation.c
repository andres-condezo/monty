#include "monty.h"

/**
 * get_operation - check op against valid opcodes.
 * @op: op to check.
 * @stack: double pointer to the beginnig of the stack.
 * @line_number: script line number.
 *
 * Return: void
 */
void get_operation(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t valid_ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};

	for (i = 0; valid_ops[i].opcode != NULL; i++)
	{
		if (strcmp(valid_ops[i].opcode, op) == 0)
		{
			valid_ops[i].f(stack, line_number);
			return;
		}
	}

	dprintf(STDERR_FILENO,
		"L%u: unknown instruction %s\n",
		line_number, op);
	exit(EXIT_FAILURE);
}
