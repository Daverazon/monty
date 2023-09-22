#include "monty.h"
/**
 * nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 */
void nop(stack_t **stack, unsigned int lnumber)
{
	(void)stack;
	(void)lnumber;
}

/**
 * pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 */
void pchar(stack_t **stack, unsigned int lnumber)
{
	if ((*stack)->next == NULL)
	{
		set_operror(pchar_error(lnumber, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_operror(pchar_error(lnumber,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 */
void pstr(stack_t **stack, unsigned int lnumber)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)lnumber;
}
