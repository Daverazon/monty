#include "monty.h"
#include <string.h>

/**
 * free_tokens - Frees the global op_token array of strings
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_token == NULL)
		return;

	for (i = 0; op_token[i]; i++)
		free(op_token[i]);

	free(op_token);
}

/**
 * token_arr_len - gets the length of the current op_token
 *
 * Return: Length of the current op_token
 */
unsigned int token_arr_len(void)
{
	unsigned int token_len = 0;

	while (op_token[token_len])
		token_len++;
	return (token_len);
}

/**
 * is_empty_line - checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line
 * @delims: A string of delimiter characters
 * Return: 1 If the line only contains delimiters else 0
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match
 * Return: A pointer to the corresponding function
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", my_div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

/**
 * run_monty - executes monty bytecode script
 * @script_fd: File descriptor for an open Monty bytecode script
 * Return: EXIT_SUCCESS on success, else respective error code on failure
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int lnumber = 0, prev_token_len = 0;
	void (*op_func)(stack_t **, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		lnumber++;
		op_token = strtow(line, DELIMS);
		if (op_token == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_token[0][0] == '#')/*comment line*/
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_token[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_operror(op_token[0], lnumber);
			free_tokens();
			break;
		}
		prev_token_len = token_arr_len();
		op_func(&stack, lnumber);
		if (token_arr_len() != prev_token_len)
		{
			if (op_token && op_token[prev_token_len])
				exit_status = atoi(op_token[prev_token_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (exit_status);
}
