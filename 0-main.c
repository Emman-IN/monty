#include "monty.h"

err err_val = {EXIT_SUCCESS, NULL};
int main(int argc, char **argv)
{
	FILE *monty_fd = NULL;

	if (argc != 2)
	{
		// if no file is passed or more than two aguements
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!monty_fd)
	{
		fprintf(stderr, "Error: Can't open file <file> %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	fclose(monty_fd);
	exit(err_val.err_stat);
}
