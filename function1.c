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

	for (i = 0: op_token[1][i]; i++)
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

	if (check_mode(*stop) == STACK)/*STACK mode insert at front*/
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
 * pall - prints all the values on the stack, starting from the top of the stack
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
