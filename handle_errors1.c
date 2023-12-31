#include "monty.h"
/**
 * pop_error - Prints pop error messages for empty stacks.
 * @lnumber: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int lnumber)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", lnumber);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 * @lnumber: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int lnumber)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", lnumber);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @lnumber: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int lnumber, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", lnumber, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division error messages for division by 0.
 * @lnumber: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int lnumber)
{
	fprintf(stderr, "L%u: division by zero\n", lnumber);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @lnumber: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int lnumber, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", lnumber, message);
	return (EXIT_FAILURE);
}
