#include "monty.h"
/**
 * rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 */
void rotl(stack_t **stack, unsigned int lnumber)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)lnumber;
}

/**
 * rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 */
void rotr(stack_t **stack, unsigned int lnumber)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)lnumber;
}

/**
 * stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 */
void stack(stack_t **stack, unsigned int lnumber)
{
	(*stack)->n = STACK;
	(void)lnumber;
}

/**
 * queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lnumber: The current working line number of a Monty bytecodes file.
 */
void queue(stack_t **stack, unsigned int lnumber)
{
	(*stack)->n = QUEUE;
	(void)lnumber;
}
