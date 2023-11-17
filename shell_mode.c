#include "shell.h"

/**
	* is_delimiter - Checks if a character is a delimiter.
	* @a: Character to check.
	* @delimiter: Delimiter string.
	*
	* Return: 1 if true, 0 if false.
	*/
int is_delimiter(char a, char *delimiter)
int is_delimiter(char a, char *delimiter);
{
	while (*delimiter)
	if (*delimiter++ == a)
	return (1);

	return (0);
}

/**
	* interactive_mode - Checks if the shell is in interactive mode.
	* @information: Pointer to struct containing shell information.
	*
	* Return: 1 if the shell is in interactive mode, 0 otherwise.
	*/
int interactive_mode(info_t *information)
{
	return (isatty(STDIN_FILENO) && information->readfd <= 2);
}

/**
	* _isalphabet - Checks if a character is an alphabet.
	* @k: Character to check.
	*
	* Return: 1 if k is an alphabet, 0 otherwise.
	*/
int _isalphabet(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
	return (1);
	else
	return (0);
}

/**
	* _atoi - Converts a given string to an integer.
	* @str: String to convert.
	*
	* Return: 0, converted number on success.
	*/
int _atoi(char *str)
{
	int j, sign = 1, flag_s = 0, product;
	unsigned int final = 0;

	for (j = 0; str[j] != '\0' && flag_s != 2; j++)
	{
	if (str[j] == '-')
	sign *= -1;

	if (str[j] >= '0' && str[j] <= '9')
	{
	flag_s = 1;
	final *= 10;
	final += (str[j] - '0');
	}
	else if (flag_s == 1)
	flag_s = 2;
	}

	if (sign == -1)
	product = -final;
	else
	product = final;

	return (product);
}
