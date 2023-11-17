#include "shell.h"

/**
	* builds_history_list - adds an entry to a linked list history
	* @info: Structure consisting of possible parameters
	* @buff: buffer
	* @line_count: counts history line
	*
	* Return: Always 0
	*/
int builds_history_list(info_t *info, char *buff, int line_count)
{
	list_t *node = NULL;

	if (info->history)
	node = info->history;
	add_node_end(&node, buff, line_count);

	if (!info->history)
	info->history = node;
	return (0);
}

/**
	* reads_history - reads history from file and forms a linked list
	* @info: the parameter struct to populate with history list
	*
	* Return: number of lines read from history file on success, 0 otherwise
	*/
int reads_history(info_t *info)
{
	int c, final = 0, line_count = 0;
	ssize_t fd, flen, fsize = 0;
	struct stat st;
	char *buff = NULL, *fileName = get_history_file(info);

	if (!fileName)
	return (0);
	fd = open(fileName, O_RDONLY);
	free(fileName);
	if (fd == -1)
	return (0);
	if (!fstat(fd, &st))
	fsize = st.st_size;
	if (fsize < 2)
	return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
	return (0);
	flen = read(fd, buff, fsize);
	buff[fsize] = '\0';
	if (flen == 0)
	return (free(buff), 0);
	close(fd);
	for (c = 0; c < fsize; c++)
	if (buff[c] == '\n')
	{
	buff[c] = '\0';
	add_node_end(&(info->history), buff + final, line_count++);
	final = c + 1;
	}
	if (final != c)
	add_node_end(&(info->history), buff + final, line_count++);
	free(buff);
	info->histcount = line_count;
	while (info->histcount-- >= HISTORY_MAX)
	delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
	* writes_history - writes history to file, overwriting existing contents
	* @info: the struct containing the history list
	*
	* Return: 1 on success, or -1 on failure
	*/
int writes_history(info_t *info)
{
	ssize_t fd;
	char *fileName = gets_history_files(info);
	list_t *node = NULL;

	if (!fileName)
	return (-1);

	fd = open(fileName, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	free(fileName);
	if (fd == -1)
	return (-1);

	for (node = info->history; node; node = node->next)
	{
	_dputsfd(node->str, fd);
	_dputfd('\n', fd);
	}

	_dputfd(BUF_FLUSH, fd);
	close(fd);

	return (1);
}

/**
	* gets_history_files - returns the path of the history file
	* @info: the parameter struct containing environment variables
	*
	* Return: allocated string containing history file path, or NULL on failure
	*/
char *gets_history_files(info_t *info)
{
	char *buf, *home_dir;

	home_dir = _getenv(info, "HOME=");
	if (!home_dir)
	return (NULL);

	buf = malloc(sizeof(char) * (_strlen(home_dir) + _strlen(HISTORY_FILE) + 2));
	if (!buf)
	return (NULL);

	buf[0] = '\0';
	_strcpyy(buf, home_dir);
	_strcatt(buf, "/");
	_strcatt(buf, HISTORY_FILE);

	return (buf);
}

/**
	* renumbers_history - renumbers the history linked list after changes
	* @info: Structure consisting of possible arguments.
	*
	* Return: the new histcounter
	*/
int renumbers_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
	node->num = i++;
	node = node->next;
	}
	return (info->histcount = i);
}
