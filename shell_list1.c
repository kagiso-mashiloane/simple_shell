#include "shell.h"

/**
 * len - Calculate the length of a linked list.
 * @current: Pointer to the head of the
 * linked list.
 * Return: Size of the linked list.
 */
size_t len(const list_t *current)
{
	size_t count = 0;

	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

/**
 * to_strings - Convert a linked list of strings
 * into an array of strings.
 * @first: Pointer to the head of the linked list.
 * Return: Array of strings or NULL if
 * unsuccessful.
 */
char **to_strings(list_t *first)
{
	list_t *c_node = first;
	size_t size = len(first), i;
	char **strs;
	char *str;

	if (!first || !size)
		return (NULL);
	strs = malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	for (i = 0; c_node; c_node = c_node->next, i++)
	{
		str = malloc(_strlen(cc_node->str) + 1);
	if (!str)
	{
		for (size_t j = 0; j < i; j++)
			free(strs[j]);
		free(strs);
		return (NULL);
	}
	str = _strcpy(str, c_node->str);
	strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print - Print the contents of a linked list.
 * @first: Pointer to the head of the linked list.
 * Return: Size of the linked list.
 */
size_t print(const list_t *first)
{
	size_t count = 0;

	while (first)
	{
	_puts(convert_number(first->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(first->str ? first->str : "(nil)");
	_puts("\n");
	count++;
	}
	return (count);
}

/**
 * sw_node - Search for a node in the linked list with
 * a given prefix and optional character.
 * @start: Pointer to the starting node for the search.
 * @prefix: Prefix to search for.
 * @c: Optional character to match after the prefix.
 * Pass -1 to ignore this condition.
 * Return: Pointer to the found node or NULL
 * if not found.
 */
list_t *sw_node(list_t *start, char *prefix, char c)
{
	char *p = NULL;

	for (; start; start = start->next)
	{
	p = starts_with(start->str, prefix);
	if (p && ((c == -1) || (*p == c)))
		return (start);
	}
	return (NULL);
}

/**
 * index_node - Find the index of a node in the
 * linked list.
 * @first: Pointer to the head of the linked list.
 * @c_node: Pointer to the node for which
 * the index is to be found.
 * Return: Index of the node in the linked list
 * or -1 if the node is not found.
 */
ssize_t index_node(list_t *first, list_t *c_node)
{
	size_t index = 0;

	for (; first; first = first->next, index++)
	{
		if (first == c_node)
			return (index);
	}
	return (-1);
}
