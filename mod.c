#include "monty.h"

/**
 * mod - compute remainder (modulus) of second element divided by top element
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	pop(stack, line_number);

	if (n == 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n %= n;
}
