#include "shell.h"

/**
 * str_length - Calculates the length of a string.
 * @str: A pointer to the string.
 * Return: The length of the string.
 **/
int str_length(char *str)
{
	int length = 0;

	if (!str)
		return (0);
	while (*str++)
		length++;
	return (length);
}

/**
 * str_compare - Compares two strings lexicographically.
 * @str1: A pointer to the first string.
 * @str2: A pointer to the second string.
 * Return: 0 if the strings are equal, a negative
 * value if str1 is less than str2,
 * and a positive value if str1 is greater than str2.
 **/
int str_compare(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
	if (*str1 != *str2)
	return (*str1 - *str2);
	str1++;
	str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * str_starts_with - Checks if a string starts
 * with a specified substring.
 * @str: Pointer to the string.
 * @substring: Pointer to the substring to check.
 * Return: If the string starts with the specified
 * substring,it returns a pointer to the character
 *in str where the substring ends. Otherwise,
 * it returns NULL.
 **/
char *str_starts_with(const char *str,
	const char *substring)
{
	while (*substring)
		if (*substring++ != *str++)
			return (NULL);
		return ((char *)str);
}

/**
 * str_concat - Concatenates two strings.
 * @result_buffer: Pointer to the destination
 * buffer where the result will be stored.
 * @source_buffer: Pointer to the source buffer.
 * Return: A pointer to the concatenated
 * string in the result_buffer.
 **/
char *str_concat(char *result_buffer,
	char *source_buffer)
{
	char *result = result_buffer;

	while (*result_buffer)
		result_buffer++;
	while (*source_buffer)
	*result_buffer++ = *source_buffer++;
	*result_buffer = '\0';
	return (result);
}
