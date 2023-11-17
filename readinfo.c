#include "shell.h"

/**
	* frees_information - Clears info_t struct fields.
	* @information: Address of a struct.
	* @comp: If non-zero, frees additional fields.
	*/
void frees_information(info_t *information, int comp)
{
	ffree(information->argv);
	information->argv = NULL;
	information->path = NULL;

	if (comp)
	{
	if (!information->cmd_buf)
	free(information->arg);

	if (information->env)
	free_list(&(information->env));

	if (information->history)
	free_list(&(information->history));

	if (information->alias)
	free_list(&(information->alias));

	ffree(information->environ);
	information->environ = NULL;

	bfree((void **)information->cmd_buf);

	if (information->readfd > 2)
	close(information->readfd);

	_putchar(BUF_FLUSH);
	}
}

/**
	* sets_information - Declares and initializes info_t structure.
	* @information: Address of a struct.
	* @av: Argument vector.
	*/
void sets_information(info_t *information, char **av)
{
	int j = 0;

	information->fname = av[0];

	if (information->arg)
	{
	information->argv = strtow(information->arg, " \t");

	if (!information->argv)
	{
	information->argv = malloc(sizeof(char *) * 2);

	if (information->argv)
	{
	information->argv[0] = _strdup(information->arg);
	information->argv[1] = NULL;
	}
	}

	for (j = 0; information->argv && information->argv[j]; j++)
	;

	information->argc = j;

	replace_alias(information);
	replace_vars(information);
	}
}

/**
	* clears_information - Declares and initializes info_t struct.
	* @information: Address of a struct.
	*/
void clears_information(info_t *information)
{
	information->arg = NULL;
	information->argv = NULL;
	information->path = NULL;
	information->argc = 0;
}
