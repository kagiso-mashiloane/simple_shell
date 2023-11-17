#include "shell.h"

/**
	* signalHandler - handles SIGINT signal (Ctrl-C)
	* @signalnum: the signal number
	*
	* Return: void
	*/
void signalHandler(__attribute__((unused))int signalnum)
void signalHandler(__attribute__((unused))int signalnum);
{
	_puts("\n$ ");
	_putchar(BUF_FLUSH);
}

/**
	* read_buffer - reads a buffer
	* @information: struct parameter
	* @buffer: buffer
	* @s: size
	*
	* Return: bytes read
	*/
ssize_t read_buffer(info_t *information, char *buffer, size_t *s)
{
	ssize_t bytes_read = 0;

	if (*s)
	return (0);

	bytes_read = read(information->readfd, buffer, READ_BUF_SIZE);

	if (bytes_read >= 0)
	*s = bytes_read;

	return (bytes_read);
}

/**
	* gets_input - gets a line minus the newline
	* @information: struct parameter
	*
	* Return: bytes read
	*/
ssize_t gets_input(info_t *information)
{
	static char *buffer; /* the ';' command chain buffer */
	static size_t i, y, len;
	ssize_t bytes_read = 0;
	char **buffer_p = &(information->arg), *p;

	_putchar(BUF_FLUSH);
	bytes_read = input_buffer(information, &buffer, &len);

	if (bytes_read == -1) /* EOF */
	return (-1);

	if (len) /* we have commands left in the chain buffer */
	{
	y = i; /* init new iterator to current buffer position */
	p = buffer + i; /* get pointer for return */

	check_chain(information, buffer, &y, i, len);

	while (y < len) /* iterate to semicolon or end */
	{
	if (is_chain(information, buffer, &y))
	break;
	y++;
	}

	i = y + 1; /* increment past nulled ';'' */

	if (i >= len) /* reached the end of buffer? */
	{
	i = len = 0; /* reset position and length */
	information->cmd_buffer_type = CMD_NORM;
	}

	*buffer_p = p; /* pass back pointer to current command position */
	return (_strlen(p)); /* return length of current command */
	}

	*buffer_p = buffer; /* not a chain: pass back buffer from custom_getline() */
	return (bytes_read); /* return length of buffer from custom_getline */
}

/**
	* input_buffer - buffers chained commands
	* @information: struct parameter
	* @buffer: address of buffer
	* @length: address of length variable
	*
	* Return: bytes read
	*/
ssize_t input_buffer(info_t *information, char **buffer, size_t *length)
{
	ssize_t bytes_read = 0;
	size_t length_p = 0;

	if (!*length)
	{
	free(*buffer);
	*buffer = NULL;
	signal(SIGINT, sigint_handler);

	/* Use getline unconditionally */
	bytes_read = getline(buffer, &length_p, stdin);

	if (bytes_read > 0)
	{
	if ((*buffer)[bytes_read - 1] == '\n')
	{
	(*buffer)[bytes_read - 1] = '\0';
	bytes_read--;
	}

	information->linecount_flag = 1;
	remove_comments(*buffer);
	build_history_list(information, *buffer, information->histcount++);

	/* Check for a command chain */
	if (_strchr(*buffer, ';'))
	{
	*length = bytes_read;
	information->cmd_buffer = buffer;
	}
	}
	}

	return (bytes_read);
}

/**
	* get_next_line - gets the next line of input from STDIN
	* @info: parameter of type struct
	* @buffer: address of pointer to a buffer, preallocated or NULL
	* @bufSize: size of preallocated buffer if not NULL
	*
	* Return: line length
	*/
int get_next_line(info_t *info, char **buffer, size_t *bufSize)
{
	static char read_buffer[READ_BUF_SIZE];
	static size_t index, len;
	size_t count;
	ssize_t read_result = 0, line_len = 0;
	char *current = NULL, *newBuf = NULL, *newline;

	current = *buffer;

	switch (current && bufSize)
	{
	case 1:
	line_len = *bufSize;
	break;
	default:
	break;
	}

	if (index == len)
	{
	index = len = 0;
	}

	read_result = read_buffer(info, read_buffer, &len);
	switch (read_result)
	{
	case -1:
	return (-1);
	case 0:
	if (len == 0)
	{
	return (-1);
	}
	break;
	default:
	break;
	}

	newline = _strchr(read_buffer + index, '\n');
	count = newline ? 1 + (unsigned int)(newline - read_buffer) : len;

	newBuf = _realloc(current, line_len, line_len ? line_len + count : count + 1);

	if (!newBuf)
	{
	/* MALLOC FAILURE! */
	if (current)
	{
	free(current);
	}
	return (-1);
	}

	switch (line_len)
	{
	case 0:
	_strncpy(newBuf, read_buffer + index, count - index + 1);
	break;
	default:
	_strncat(newBuf, read_buffer + index, count - index);
	break;
	}
	line_len += count - index;
	index = count;
	current = newBuf;

	if (bufSize)
	{
	*bufSize = line_len;
	}

	*buffer = current;

	return (line_len);
}
