#include "shell.h"

/**
 * _myaliases - The alias builtin replica.
 * @shell_info: Structure consisting of possible arguments.
 *
 * Return: Always 0.
 */
int _myaliases(info_t *shell_info)
{
	int j = 0;
	char *i = NULL;
	list_t *node = NULL;

	if (shell_info->argc == 1)
	{
	node = shell_info->alias;
	while (node)
	{
		_prints_alias(node);
		node = node->next;
	}
	return (0);
	}
	for (j = 1; shell_info->argv[j]; j++)
	{
	i = strchr(shell_info->argv[j], '=');
	if (i)
	sets_alias(shell_info, shell_info->argv[j]);
	else
	_prints_alias(
	str_starts_with(shell_info->alias, shell_info->argv[j], '=')
	);
	}
	return (0);
}

/**
 * sets_alias - Sets an alias string.
 * @shell_info: Pointer to struct containing shell information.
 * @ptr: The string alias.
 * Return: Always 0 on success, 1 on failure.
 */
int sets_alias(info_t *shell_info, char *ptr)
{
	char *s;

	s = my_strchr(ptr, '=');
	if (!s)
		return (1);
	if (!*++s)
	return (unsets_alias(shell_info, ptr));

	unsets_alias(shell_info, ptr);
	return (add_end(&(shell_info->alias), ptr, 0) == NULL);
}

/**
 * unsets_alias - Deletes an alias string.
 * @shell_info: Pointer to struct containing shell information.
 * @ptr: The string alias.
 * Return: Always 0 on success, 1 on failure.
 */
int unsets_alias(info_t *shell_info, char *ptr)
{
	char *s, o;
	int rev;

	s = _strchr(ptr, '=');
	if (!s)
	return (1);
	o = *s;
	*s = 0;
	rev = deleteNodeAtIndex(&(shell_info->alias),
	getNodeIndex(shell_info->alias,
		str_starts_with(shell_info->alias, ptr, -1)));
	*s = o;
	return (rev);
}

/**
 * print_alias - Prints an alias string.
 * @node: The alias node.
 * Return: Always 0 on success, 1 on failure.
 */
int print_alias(list_t *node)
{
	char *c = NULL, *b = NULL;

	if (node)
	{
	c = _strchr(node->str, '=');
	for (b = node->str; b <= c; b++)
		put_char(*b);
	put_char('\'');
	_puts(c + 1);
	_puts("'\n");
	return (0);
	}
	return (1);
}

