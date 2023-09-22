#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_token = NULL;

/**
 * main - entry point into the program
 * @argc: number of arguments passed to program
 * @argv: pointer to array of char pointers to arguments
 * Return: (EXIT_SUCCESS) on success, (EXIT_FAILURE) on failure
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fdopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
