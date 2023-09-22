#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @top: address of pointer to top of a stack_s doubly linked list stack
 * @lnumber: current working line number of a monty bytecode file
 */
void push(stack_t **top, unsigned int lnumber)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		set_operror(malloc_error());
		return;
	}

	if (op_token[1] == NULL)
	{
		set_operror(no_interror(lnumber));
		return;
	}

	for (i = 0; op_token[1][i]; i++)
	{
		if (op_token[1][i] == 'i' && i == 0)
			continue;
		if (op_token[1][i] < '0' || op_token[1][i] > '9')
		{
			set_operror(no_interror(lnumber));
			return;
		}
	}
	new->n = atoi(op_token[1]);

	if (check_mode(*top) == STACK)/*STACK mode insert at front*/
	{
		tmp = (*top)->next;
		new->prev = *top;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*top)->next = new;
	}
	else /*QUEUE mode insert at end*/
	{
		tmp = *top;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}


/**
 * pall - print all the values on the stack, starting from the top of the stack
 * @top: address of pointer to tail of a stack_s doubly linked list stack
 * @lnumber: current working line number of a monty bytecode file
 */
void pall(stack_t **top, unsigned int lnumber)
{
	stack_t *tmp = (*top)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)lnumber;
}

/**
 * pint - prints the top value of a stack_t linked list
 * @stack: pointer to the top node of a sack_t linked list
 * @lnumber: current working line number of a monty bytecode file
 */
void pint(stack_t **stack, unsigned int lnumber)
{
	if ((*stack)->next == NULL)
	{
		set_operror(pint_error(lnumber));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * pop - removes the top value element of a stack_t linked list
 * @stack: pointer to top node of a stack_t linked list
 * @lnumber: current working file number of a monty bytecode fi
 */
void pop(stack_t **stack, unsigned int lnumber)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_operror(pop_error(lnumber));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swap - swaps the top two value elements of a stack_t linked list
 * @stack: a pointer to the top node of a stack_t linked list
 * @lnumber: current working line number of a monty bytecode fi    le
 */
void swap(stack_t **stack, unsigned int lnumber)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_operror(short_stack_error(lnumber, "swap"));
		return;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
