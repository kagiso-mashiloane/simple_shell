#include "shell.h"
/**
 * copy_str - Copies the contents of the source
 * string to the destination string.
 * @dest: Destination string.
 * @src: Source string.
 * Return: Pointer to the destination string.
 **/
char *copy_str(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
 * str_duplicate - Creates a duplicate of
 * the input string.
 * @src: Input string.
 * Return: Pointer to the duplicated string.
 **/
char *str_duplicate(const char *src)
{
	int len = 0;
	char *dup;

	if (src == NULL)
		return (NULL);
	while (*src++)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (len++; len--;)
		dup[len] = *--src;
	return (dup);
}
/**
 * put_str - Prints a string to the
 * standard output.
 * @str: Input string.
 * Return: Nothing
 **/
void put_str(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		put_char(str[i]);
		i++;
	}
}
/**
 * put_char - Prints a character to the
 * standard output.
 * @c: Character to be printed.
 *
 * Return: Always returns 1.
 **/
int put_char(char c)
{
	static int idx;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || idx >= WRITE_BUF_SIZE)
	{
		write(1, buf, idx);
		idx = 0;
	}
	if (c != BUF_FLUSH)
		buf[idx++] = c;
	return (1);
}
