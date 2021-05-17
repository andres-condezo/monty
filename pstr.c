#include "monty.h"

/**
 * pstr - Prints the str starting at the top, followed by a new line.
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp = (*stack);

	while (tmp && tmp->n != 0 && ((*stack)->n > 0 || (*stack)->n < 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

}
