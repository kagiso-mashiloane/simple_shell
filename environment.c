#include"shell.h"
/**
 * getValueOfEnvVar - gets the value of an environment variable
 * @infor: Struct containing possible arguments.
 * @var_name: environment variable name
 *
 * Return: the value of an environment
 */
char *getValueOfEnvVar(info_t *infor, const char *var_name)
{
	list_t *node = infor->env;
	char *s;

	while (node)
	{
	s = startsWith(node->string, var_name);
	if (s && *s)
		return (s);
	node = node->next;
	}
	return (NULL);
}

/**
 * printEnvironment - prints the current environment
 * @infor: Struct of possible arguments.
 *
 * Return: Always 0
 */
int printEnvironment(info_t *infor)
{
	printLinkedListStr(infor->env);
	return (0);
}
/**
 * initializeEnvVar - Initializes a new environment variable,
 *                    or modify an existing variable
 * @infor: Struct of potential arguments.
 *
 * Return: Always 0
 */
int initializeEnvVar(info_t *infor)
{
	if (infor->argc != 3)
	{
	_eputs("Invalid number of arguments\n");
	return (1);
	}
	if (setEnvVar(info, infor->argv[1], infor->argv[2]))
	{
		return (0);
	}
	return (1);
}
/**
 * populateEnvironmentList - populates the environment linked list
 * @infor: Struct of posible arguments
 *
 * Return: Always 0
 */
int populateEnvironmentList(info_t *infor)
{
	list_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
	addNodeEnd(&node, environ[j], 0);
	info->env = node;
	return (0);
}
/**
 * removeEnvVar - Removes an environment variable
 * @infor: Structure consisting of potential arguments.
 *
 * Return: Always(0);
 */
int removeEnvVar(info_t *infor)
{
	int j;

	if (infor->argc == 1)
	{
	_eputs("missing an argument.\n");
	return (1);
	}
	for (j = 1; j <= infor->argc; j++)
	{
	unsetEnvVar(infor, infor->argv[i]);
	return (0);
	}
}
