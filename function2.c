#include "monty.h"

/**
 * add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void add(stack_t **stack, unsigned int lnumber)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_operror(short_stack_error(lnumber, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, lnumber);
}

/**
 * sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void sub(stack_t **stack, unsigned int lnumber)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_operror(short_stack_error(lnumber, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, lnumber);
}

/**
 * div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void my_div(stack_t **stack, unsigned int lnumber)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_operror(short_stack_error(lnumber, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_operror(div_error(lnumber));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, lnumber);
}

/**
 * mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mul(stack_t **stack, unsigned int lnumber)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_operror(short_stack_error(lnumber, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, lnumber);
}

/**
 * mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mod(stack_t **stack, unsigned int lnumber)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_operror(short_stack_error(lnumber, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_operror(div_error(lnumber));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, lnumber);
}
