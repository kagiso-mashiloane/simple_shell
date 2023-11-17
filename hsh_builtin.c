#include "shell.h"
/**
 * helpinfo_shell - prints help message
 * @information: pointer to struct which contains shell information
 *
 * Return: Always 0
 */
int helpinfo_shell(info_t *information)
{
	char **array;

	array = information->argv;
	_puts("help functions as expected \n");
	if (0)
		_puts(*array);
	return (0);
}

/**
 * change_c_directory - changes from one directory to another
 * @information: pointer to struct containing shell information
 *
 * Return:  0
 */
int change_c_directory(info_t *information)
{
	char *p, *directory, buf[1024];
	int chdir_return;

	p = getcwd(buf, 1024);
	if (!p)
		_puts("process failed…\n");
	if (!information->argv[1])
	{
		directory = _getenv(information, "HOME=");
		if (!directory)
			chdir_return = /* TODO: what should this be? */
				chdir((directory = _getenv(information, "PWD=")) ? directory : "/");
		else
			chdir_return = chdir(directory);
	}
	else if (_strcmp(information->argv[1], "-") == 0)
	{
		if (!_getenv(information, "OLDPWD="))
		{
			_puts(p);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(information, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(information, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(information->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(information, "cannot execute cd  ");
		_eputs(information->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(information, "OLDPWD", _getenv(information, "PWD="));
		_setenv(information, "PWD", getcwd(buf, 1024));
	}
	return (0);
}
/**
 * exit_ssh - exits the shell
 * @information: pointer to struct that contains shell information
 *
 * Return: exits with a specific exit status,
 *         (0) if info.argv[0] != "exit"
 */
int exit_ssh(info_t *information)
{
	int exit_check;

	if (information->argv[1])  /* If  exit arguments exist */
	{
		exit_check = _erratoi(infomation->argv[1]);
		if (exit_check == -1)
		{
			infomation->status = 2;
			print_error(infomation, "Illegal number: ");
			_eputs(information->argv[1]);
			_eputchar('\n');
			return (1);
		}
		information->err_num = _erratoi(infomation->argv[1]);
		return (-2);
	}
	information->err_num = -1;
	return (-2);
}
