#include "shell.h"

/**
	* string_concatenator - Concatenates two strings.
	* @str1: The first string.
	* @str2: The second string.
	* @num_bytes: The maximum amount of bytes to be used.
	*
	* Return: The concatenated string.
	*/
char *string_concatenator(char *str1, char *str2, int num_bytes)
{
	int c, k;
	char *s = str1;

	c = 0;
	k = 0;
	while (str1[c] != '\0')
	c++;
	while (str2[k] != '\0' && k < num_bytes)
	{
	str1[c] = str2[k];
	c++;
	k++;
	}
	if (k < num_bytes)
	str1[c] = '\0';

	return (s);
}

/**
	* string_copier - Copies a string.
	* @destination: The destination string to be copied to.
	* @source: The source string.
	* @num_chars: The number of characters to be copied.
	*
	* Return: The copied string.
	*/
char *string_copier(char *destination, char *source, int num_chars)
{
	int y, j;
	char *str = destination;

	y = 0;
	while (source[y] != '\0' && y < num_chars - 1)
	{
	destination[y] = source[y];
	y++;
	}
	if (y < num_chars)
	{
	j = y;
	while (j < num_chars)
	{
	destination[j] = '\0';
	j++;
	}
	}

	return (str);
}

/**
	* find_character - Finds a character in a string.
	* @ptr: The string to be parsed.
	* @character: The character to search for.
	*
	* Return: A pointer to the memory area of the character.
	*/
char *find_character(char *ptr, char character)
{
	do {
	if (*ptr == character)
	return (ptr);
	} while (*ptr++ != '\0');

	return (NULL);
}
