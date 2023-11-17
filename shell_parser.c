#include "shell.h"

/**
 * is_exec - Checks if a file is executable.
 * @i: Pointer to the info structure
 * @p: Path to the file.
 *
 * Return: 1 if the file is executable,
 * 0 otherwise.
 */
int is_exec(info_t *i, char *p)
{
	struct stat s;

	(void)i;
	if (!p || stat(p, &s))
		return (0);

	if (s.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_ch - Duplicates a substring of a string
 * excluding ':' characters.
 * @ps: The string.
 * @s: Start index.
 * @e: End index.
 * Return: Pointer to the duplicated substring.
 */
char *dup_ch(char *ps, int s, int e)
{
	static char b[1024];
	int i = 0, k = 0;

	for (k = 0, i = s; i < e; i++)
	if (ps[i] != ':')
		b[k++] = ps[i];
	b[k] = 0;
	return (b);
}

/**
 * find_p - Finds the full path of a
 * command in the system's PATH.
 * @i: Pointer to the info structure
 * @ps: The PATH variable string.
 * @c: The command to find in the PATH.
 *
 * Return: Pointer to the full path of
 * the command if found and executable,
 * NULL otherwise.
 */
char *find_p(info_t *i, char *ps, char *c)
{
	int x = 0, cp = 0;
	char *p;

	if (!ps)
		return (NULL);
	if ((_strlen(c) > 2) && starts_with(c, "./"))
	{
	if (is_exec(i, c))
		return (c);
	}
	while (1)
	{
	switch (ps[x])
	{
	case '\0':
	case ':':
		p = dup_ch(ps, cp, x);
		if (!*p)
			_strcat(p, c);
		else
		{
			_strcat(p, "/");
			_strcat(p, c);
		}

		if (is_exec(i, p))
			return (p);
		if (!ps[x])
			break;
		cp = x;
		break;
		}
		x++;
	}
	return (NULL);
}
