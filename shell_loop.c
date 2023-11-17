#include "shell.h"

/**
 * shell - Main function to run the shell.
 * @si: A pointer to the shell information structure.
 * @args: An array of strings representing
 * command-line arguments.
 * Return: Returns the exit status of the shell.
 */
int shell(info_t *si, char **args)
{
	ssize_t input_res = 0;
	int ret = 0;

	while (input_res != -1 && ret != -2)
	{
		clear_info(si);
		if (interactive_mode(si))
			put_str("$ ");
		_dputchar(BUF_FLUSH);
		input_res = gets_input(si);
		if (input_res != -1)
		{
			set_info(si, args);
			ret = bshell(si);
			if (ret == -1)
				cmdfind(si);
		}
		else if (interactive(si))
			put_char('\n');
		free_info(si, 0);
	}
	writes_history(si);
	free_info(si, 1);

	if (!interactive(si) && si->status)
		exit(si->status);
	if (ret == -2)
	{
		if (si->error_number == -1)
			exit(si->status);
		exit(si->error_number);
	}
	return (ret);
}

/**
 * bshell - Executes built-in shell commands.
 * @si: A pointer to the shell information structure.
 * Return: Returns the exit status of the command.
 */
int bshell(info_t *si)
{
	int i, ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};
	for (i = 0; builtintbl[i].type; i++)
	if (_strcmp(si->argv[0], builtintbl[i].type) == 0)
	{
		si->line_count++;
		ret = builtintbl[i].func(si);
		break;
	}
	return (ret);
}

/**
 * cmdfind - Finds the command in the system's PATH or
 * checks if it's a built-in command.
 * @si: A pointer to the shell information structure.
 */
void cmdfind(info_t *si)
{
	char *path = NULL;
	int i, k;

	si->path = si->argv[0];
	if (si->linecount_flag == 1)
	{
		si->line_count++;
		si->linecount_flag = 0;
	}
	for (i = 0, k = 0; si->args[i]; i++)
		if (!is_delim(si->args[i], " \t\n"))
			k++;
	if (!k)
		return;
	path = find_path(si, _getenv(si, "PATH="), si->argv[0]);
	if (path)
	{
		si->path = path;
		forkcmd(si);
	}
	else
	{
	if ((interactive(si) || _getenv(si, "PATH=") ||
	si->argv[0][0] == '/') && is_cmd(si, si->argv[0]))
	)
		forkcmd(si);
	else if (*(si->args) != '\n')
	{
		si->status = 127;
		prints_error(si, "not found\n");
	}
	}
}

/**
 * forkcmd - Forks a child process to execute an external command.
 * @si: A pointer to the shell information structure.
 */
void forkcmd(info_t *si)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
	if (execve(si->path, si->argv, get_environ(si)) == -1)
	{
		free_info(si, 1);
		if (errno == EACCES)
			exit(126);
		exit(1);
	}
	}
	else
	{
		wait(&(si->status));
		if (WIFEXITED(si->status))
		{
		si->status = WEXITSTATUS(si->status);
		if (si->status == 126)
			print_error(si, "Permission denied\n");
		}
	}
}

