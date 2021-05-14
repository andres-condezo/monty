#include "monty.h"

/**
 * free_line_ptr - free line pointer returned by getline.
 * @status: exit status.
 * @arg: pointer to line.
 *
 * Return: void.
 */
void free_line_ptr(int status, void *arg)
{
	char **line_ptr = arg;

	(void)status;

	if (*line_ptr != NULL)
		free(*line_ptr);
}
