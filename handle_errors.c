#include <monty.h>

/**
 * no_interror: prints invalid argument push error messages
 *
 * Return: always returns EXIT_FAILURE
 */
int no_interror(unsigned int lnumber)
{
	fprintf(stderr, "L%d:  usage: push integer\n", lnumber);
	return (EXIT_FAILURE);
}
/**
 * malloc_error: prints malloc error messages
 *
 * Return: always returns EXIT_FAILURE
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * usage_error: prints usage error messages
 *
 * Return: always returns EXIT_FAILURE
 */
int usage_error(void)
{
	fprint(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * fd_open_error - prints file open error messages
 * @filename: Neme of file failed to open
 * Return: always returns EXIT_FAILURE
 */
int fd_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
