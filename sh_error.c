#include "shell.h"

/**
	* printErrorString - Prints an input string.
	* @string: The string to be printed.
	*
	* Return: Nothing.
	*/
void printErrorString(char *string)
{
	int p = 0;

	if (!string)
	return;
	while (string[p] != '\0')
	{
	printErrorCharacter(string[p]);
	p++;
	}
}

/**
	* putCharacterToFD - Writes the character to a given file descriptor.
	* @d: The character to print.
	* @fd: The file descriptor to write to.
	*
	* Return: 1 on success. On error, -1 is returned.
	*/
int putCharacterToFD(char d, int fd)
{
	static int j;
	static char buff[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
	write(fd, buff, j);
	j = 0;
	}
	if (d != BUF_FLUSH)
	buff[j++] = d;
	return (1);
}

/**
	* printErrorCharacter - Writes the character to stderr.
	* @a: The character to print.
	*
	* Return: On success 1. On error, -1 is returned.
	*/
int printErrorCharacter(char a)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
	write(2, buf, k);
	k = 0;
	}
	if (a != BUF_FLUSH)
	buf[k++] = a;
	return (1);
}

/**
	* printStringToFD - Prints an input string to a given file descriptor.
	* @strr: The string to be printed.
	* @fd: The file descriptor to write to.
	*
	* Return: The number of characters printed.
	*/
int printStringToFD(char *strr, int fd)
{
	int j = 0;

	if (!strr)
	return (0);
	while (*strr)
	{
	j += putCharacterToFD(*strr++, fd);
	}
	return (j);
}
