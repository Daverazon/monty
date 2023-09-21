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
