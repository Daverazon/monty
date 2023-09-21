#include "monty.h"

/**
 * no_interror - prints invalid argument push error messages
 * @lnumber: line number of a monty bytecode file where error occurred
 * Return: always returns EXIT_FAILURE
 */
int no_interror(unsigned int lnumber)
{
	fprintf(stderr, "L%d:  usage: push integer\n", lnumber);
	return (EXIT_FAILURE);
}
/**
 * malloc_error - prints malloc error messages
 *
 * Return: always returns EXIT_FAILURE
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * usage_error - prints usage error messages
 *
 * Return: always returns EXIT_FAILURE
 */
int usage_error(void)
{
	fprint(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * f_open_error - prints file open error messages
 * @filename: Neme of file failed to open
 * Return: always returns EXIT_FAILURE
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
/**
 * unknown_operror - prints unknown instruction error message
 * @opcode: opcode where error occurred
 * @lnumber: line number of a monty bytecode file where error occured
 * Return: always return EXIT_FAILURE
 */
int unknown_operror(char *opcode, unsigned int lnumber)
{
	fprint(stderr, "L%u: unknown instruction %s\n", lnumber, opcode);
	return (EXIT_FAILURE);
}
