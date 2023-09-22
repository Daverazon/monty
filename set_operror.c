#include "monty.h"

/**
 * set_operror - sets last element of op_token to be an error code
 * @error_code: integer to store as a string in op_toks
 */
void set_operror(int error_code)
{
	int token_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_token = NULL;

	token_len = token_arr_len();
	new_token = malloc(sizeof(char *) * (token_len + 2));
	if (!op_token)
	{
		malloc_error();
		return;
	}
	while (i < token_len)
	{
		new_token[i] = op_token[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_token);
		malloc_error();
		return;
	}
	new_token[i++] = exit_str;
	new_token[i] = NULL;
	free(op_token);
	op_token = new_token;
}
