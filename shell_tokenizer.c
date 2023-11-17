#include "shell.h"

/**
 * splitStr - Splits a string into words.
 * Repeat delimiters are ignored.
 * @s: The input string.
 * @d: The delimiter string.
 * Return: A pointer to an array of strings,
 * or NULL on failure.
 **/
char **splitStr(char *s, char *d)
{
	int i, j, k, m, n = 0;
	char **w;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!d)
	d = " ";

	for (i = 0; s[i] != '\0'; i++)
	if (!isDelim(s[i], d) && (isDelim(s[i + 1], d) || !s[i + 1]))
		n++;
	if (n == 0)
	return (NULL);
	w = malloc((1 + n) * sizeof(char *));
	if (!w)
	return (NULL);

	for (i = 0, j = 0; j < n; j++)
	{
	while (isDelim(s[i], d))
	i++;
	k = 0;
	while (!isDelim(s[i + k], d) && s[i + k])
	k++;
	w[j] = malloc((k + 1) * sizeof(char));
	if (!w[j])
	{
	for (k = 0; k < j; k++)
	free(w[k]);
	free(w);
	return (NULL);
	}
	for (m = 0; m < k; m++)
		w[j][m] = s[i++];
	w[j][m] = 0;
	}
	w[j] = NULL;
	return (w);
}

/**
 * splitStr2 - Splits a string into words.
 * @s: The input string.
 * @d: The delimiter.
 * Return: A pointer to an array of strings,
 *or NULL on failure.
 **/
char **splitStr2(char *s, char d)
{
	int i, j, k, m, n = 0;
	char **w;

	if (s == NULL || s[0] == 0)
	return (NULL);
	for (i = 0; s[i] != '\0'; i++)
	if ((s[i] != d && s[i + 1] == d) ||
		(s[i] != d && !s[i + 1]) || s[i + 1] == d)
	n++;
	if (n == 0)
	return (NULL);
	w = malloc((1 + n) * sizeof(char *));
	if (!w)
	return (NULL);
	for (i = 0, j = 0; j < n; j++)
	{
	while (s[i] == d && s[i] != d)
	i++;
	k = 0;
	while (s[i + k] != d && s[i + k] && s[i + k] != d)
	k++;
	w[j] = malloc((k + 1) * sizeof(char));
	if (!w[j])
	{
		for (k = 0; k < j; k++)
			free(w[k]);
		free(w);
		return (NULL);
	}
	for (m = 0; m < k; m++)
		w[j][m] = s[i++];
	w[j][m] = 0;
	}
	w[j] = NULL;
	return (w);
}
