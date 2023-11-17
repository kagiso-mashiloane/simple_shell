#include"shell.h"
/**
 * removeEnvVar - Remove an environment variable
 * @info_Struct: Structure containing possible arguments, used to maintain
 *        constant function prototype.
 * @varName: The name of the environment variable to remove
 * Return: 1 on success, 0 otherwise
 */
int removeEnvVar(info_t *info_Struct, char *varName)
{
	list_t *node = info_Struct->envList;
	size_t index = 0;
	char *p;

	if (!node || !varName)
	return (0);

	while (node)
	{
	p = startsWith(node->str, varName);
	if (p && *p == '=')
	{
	info_Struct->envChanged = deleteNodeAtIndex(&(info_Struct->envList), index);
	index = 0;
	node = info_Struct->envList;
	continue;
	}
	node = node->next;
	index++;
	}
	return (info_Struct->envChanged);
}
/**
 * setEnvVar - Initializes and modifies environment variables
 * @infoStruct: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @varName: The name of the environment variable to set
 * @value: The value of the environment variable
 * Return: Always 0
 */
int setEnvVar(info_t *infoStruct, char *varName, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *p;

	if (!varName || !value)
	return (0);

	buff = malloc(_strlen(varName) + _strlen(value) + 2);
	if (!buff)
	return (1);

	_strcpy(buff, varName);
	_strcat(buff, "=");
	_strcat(buffer, value);

	node = infoStruct->envList;
	while (node)
	{
	p = startsWith(node->str, varName);
	if (p && *p == '=')
	{
	free(node->str);
	node->str = buffer;
	break;
	}
	node = node->next;
	}
	return (0);
}

/**
 * getEnvironment - copies the current environment variables as a string array
 * @info_Struct: Structure consisting of possible arguments.
 * Return: Pointer to the array of strings of the environment variables.
 */
char **getEnvironment(info_t *info_Struct)
{
	if (!info_Struct->envArray || info_Struct->envChanged)
	{
	info_Struct->envArray = listToStrings(info_Struct->envList);
	info_Struct->envChanged = 0;
	}
	return (info_Struct->envArray);
}
