#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: Number of command-line arguments
 * @argv: Array of strings representing
 * command-line arguments
 *
 * Return: EXIT_SUCCESS on success,
 * EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	info_t my_info[] = { INFO_INIT };
	int my_fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (my_fd)
		: "r" (my_fd));
	switch (argc)
	{
	case 2:
		my_fd = open(argv[1], O_RDONLY);
		if (my_fd == -1)
		{
		switch (errno)
		{
		case EACCES:
			exit(126);
		case ENOENT:
			_eputs(argv[0]);
			_eputs(": 0: Can't open ");
			_eputs(argv[1]);
			_eputchar('\n');
			_eputchar(BUF_FLUSH);
			exit(127);
		default:
			return (EXIT_FAILURE);
		}
		}
		my_info->readfd = my_fd;
		break;
	default:
		break;
	}
	populateEnvironmentList(my_info);
	reads_history(my_info);
	shell(my_info, argv);
	return (EXIT_SUCCESS);
}

