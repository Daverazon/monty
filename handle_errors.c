#include <monty.h>

/**
 * malloc_error: prints malloc error messages
 *
 * Return: always returns EXIT_FAILURE
 */

int no_interror(unsigned int lnumber)
{
	fprintf(stderr, "L%d:  usage: push integer\n", lnumber);
	return;
}
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
