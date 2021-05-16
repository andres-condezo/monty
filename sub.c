#include "monty.h"

/**
 * sub - subtract top element of stack from next element and push result.
 * @stack: double pointer to head of stack.
 * @line_number: line number of current operation.
 *
 * Return: void.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= n;
}
