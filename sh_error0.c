#include "shell.h"

/**
* error_atoi - Converts a string to an integer.
* @str: The string to be converted.
*
* Return: 0 if there’s no number in a string, converted number otherwise.
*         -1 on error.
**/
int error_atoi(char *str)
{
	int p = 0;
	unsigned long int results = 0;

	if (*str == '+')
	str++;

	for (p = 0; str[p] != '\0'; p++)
	{
	if (str[p] >= '0' && str[p] <= '9')
	{
	results *= 10;
	results += (str[p] - '0');
	if (results > INT_MAX)
	return (-1);
	}
	else
	return (-1);
	}
	return (results);
}

/**
* print_dec - Prints a decimal (integer) number (base 10).
* @num: The input integer.
* @fd: The file descriptor to write to.
*
* Return: Number of printed characters.
*/
int print_dec(int num, int fd)
{
	int (*put_char)(char) = put_char;
	int y, counter = 0;
	unsigned int abs_value, curr;

	if (fd == STDERR_FILENO)
	put_char = _dputchar;

	if (num < 0)
	{
	abs_value = -num;
	put_char('-');
	counter++;
	}
	else
	abs_value = num;

	curr = abs_value;

	for (y = 1000000000; y > 1; y /= 10)
	{
	if (abs_value / y)
	{
	put_char('0' + curr / y);
	counter++;
	}
	curr %= y;
	}
	put_char('0' + curr);
	counter++;

	return (counter);
}

/**
	* prints_error - Prints an error message.
	* @information: The parameter and return information structure.
	* @str: String containing specified error type.
	*
	* Return: Nothing.
	*/
void prints_error(info_t *information, char *str)
{
	_dputs(information->fname);
	_dputs(": ");
	print_dec(information->line_count, STDERR_FILENO);
	_dputs(": ");
	_dputs(information->argv[0]);
	_dputs(": ");
	_dputs(str);
}

/**
	* num_converter - Converts a number to a string representation.
	* @numb: Number to be converted.
	* @_base: Base to convert to.
	* @flaggs: Argument flags.
	*
	* Return: String representation of the number.
	*/
char *num_converter(long int numb, int _base, int flaggs)
{
	static char *arr;
	static char buff[50];
	char sig = 0;
	char *str;
	unsigned long i = numb;

	if (!(flaggs & CONVERT_TO_UNSIGNED) && (numb < 0)
	{
	i = -numb;
	sig = '-';
	}

	arr = flaggs & CONVERT_TO_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buff[49];
	*str = '\0';

	do {
	*--str = arr[i % _base];
	i /= _base;
	} while (i != 0);

	if (sig)
	*--str = sig;

	return (str);
}

/**
	* delete_comments - Replaces the first ocurrance '#' with '\0'.
	* @buff: Address of the string to be modified.
	*
	* Return: Always 0.
	*/
void delete_comments(char *buff)
{
	int y;

	for (y = 0; buff[y] != '\0'; y++)
	if (buff[y] == '#' && (!y || buff[y - 1] == ' '))
	{
	buff[y] = '\0';
	break;
	}
}
