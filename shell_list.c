#include "shell.h"
/**
 * add - Adds a new node at the beginning of
 * a linked list.
 * @h: Pointer to the head of the linked list.
 * @s: String to be stored in the new node
 * @n: Integer to be stored in the new node.
 * Return: Pointer to the newly added node.
 */
list_t *add(list_t **h, const char *s, int n)
{
	list_t *new_node;

	if (!h)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = n;

	switch (s != NULL)
	{
	case 1:
		new_node->str = _strdup(s);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
		break;
	default:
		break;
	}
	new_node->next = *h;
	*h = new_node;
	return (new_node);
}
/**
 * add_end - Adds a new node at the end of a
 * linked list.
 * @h: Pointer to the head of the linked list.
 * @s: String to be stored in the new node
 * @n: Integer to be stored in the new node.
 * Return: Pointer to the newly added node.
 */
list_t *add_end(list_t **h, const char *s, int n)
{
	list_t *new_node, *current;

	if (!h)
		return (NULL);
	current = *h;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = n;

	switch (s != NULL)
	{
	case 1:
		new_node->str = _strdup(s);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
		break;
	default:
		break;
	}
	switch (!!current)
	{
	case 1:
		while (current->next)
			current = current->next;
			current->next = new_node;
		break;
	default:
		*h = new_node;
		break;
	}
	return (new_node);
}

/**
 * print_str - Prints the strings stored in each
 * node of a linked list.
 * @n: Pointer to the head of the linked list.
 * Return: The number of nodes in the linked list.
 */
size_t print_str(const list_t *n)
{
	size_t i = 0;

	while (n)
	{
		switch (n->str != NULL)
		{
		case 1:
			_puts(n->str);
			break;
		default:
			_puts("(nil)");
			break;
		}
	_puts("\n");
	n = n->next;
	i++;
	}
	return (i);
}
/**
 * delete_at_index - Deletes the node at a specified
 * index in a linked list.
 * @h: Pointer to the head of the linked list.
 * @index: Index of the node to be deleted.
 * Return: 1 if deletion is successful, 0 otherwise.
 */
int delete_at_index(list_t **h, unsigned int index)
{
	list_t *node, *prev;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);
	switch (!!index)
	{
	case 1:
		node = *h;
		*h = (*h)->next;
		free(node->str);
		free(node);
		return (1);
	default:
		node = *h;
		while (node)
		{
		if (i == index)
		{
		prev->next = node->next;
		free(node->str);
		free(node);
		return (1);
		}
	i++;
	prev = node;
	node = node->next;
	}
	return (0);
	}
}
/**
 * free_list - Frees the memory allocated for
 * a linked list.
 * @h: Pointer to the head of the linked list.
 */
void free_list(list_t **h)
{
	list_t *node, *next, *head;

	if (!h || !*h)
		return;
	head = *h;
	node = head;

	while (node)
	{
		next = node->next;
		free(node->str);
		free(node);
		node = next;
	}
	*h = NULL;
}
