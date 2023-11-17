#include "shell.h"
#include <string.h>
/**
 * is_cmd - test if current char in cmd_buf is
 * a chain delimiter
 * @cmd_info: the parameter struct
 * @cmd_buf: the char buffer
 * @pos: address of current position in cmd_buf
 * Return: 1 if chain delimiter, 0 otherwise
 */
int is_cmd(info_t *cmd_info, char *cmd_buf, size_t *pos)
{
	size_t i = *pos;

	switch (cmd_buf[i])
	{
	case '|':
		if (cmd_buf[i + 1] == '|')
		{
			cmd_buf[i] = 0;
			i++;
			CMDL_OR = cmd_info->cmd_buf_type;
			break;
		}
	case '&':
		if (cmd_buf[i + 1] == '&')
		{
			cmd_buf[i] = 0;
			i++;
			CMDL_AND = cmd_info->cmd_buf_type;
			break;
		}
	case ';':
		cmd_buf[i] = 0;
		CMDL_CHAIN = cmd_info->cmd_buf_type;
		break;
	default:
		return (0);
	}
	*pos = i;
	return (1);
}

/**
 * chk_cmd - checks if we should continue
 * chaining based on last status
 * @cmd_info: the parameter struct
 * @cmd_buf: the char buffer
 * @pos: address of current position in cmd_buf
 * @start_pos: starting position in cmd_buf
 * @len: length of cmd_buf
 * Return: Void
 */
void chk_cmd(info_t *cmd_info, char *cmd_buf,
size_t *pos, size_t start_pos, size_t len)
{
	size_t i = *pos;
	char 
	switch (cmd_info->cmd_buf_type)
	{
	case CMDL_AND:
			if (cmd_info->status)
			{
			cmd_buf[start_pos] = 0;
			i = len;
			}
		break;
	case CMDL_OR:
			if (!cmd_info->status)
			{	
			cmd_buf[start_pos] = 0;
			i = len;
			}
			break;
	}
	*pos = i;
}

/**
 * rep_alias - replaces an alias in the
 * tokenized string
 * @cmd_info: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int rep_alias(info_t *cmd_info)
{
	int i;
	list_t *node;
	char *value;
	char single_char_str[2] = {cmd_info->args[0], '\0'};
	char *args[MAX_ARGS];

	for (i = 0; i < 10; i++)
	{
	node = str_starts_with(cmd_info->alias->data, single_char_str, '=');
	if (!node)
		return (0);
	if (cmd_info->args[0] != NULL) 
	{
		free(cmd_info->args[0]);
	} 
	value = my_strchr(node->str, '=');
	if (!value)
		return (0);
	value = my_strdup(value + 1);
	if (!value)
		return (0);
	cmd_info->args[0] = value;
	}
	return (1);
}

/**
 * rep_vars - replaces variables in the tokenized string
 * @cmd_info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int rep_vars(info_t *cmd_info)
{
	int i = 0;
	list_t *node;

	for (i = 0; cmd_info->args[i]; i++)
	{
	if (cmd_info->args[i] != NULL && (cmd_info->args[i][0] != '$' || cmd_info->args[i][1] == '\0')) 
	{
		continue;
	}
	if (!my_strcmp(cmd_info->args[i], "$?"))
	{
	rep_str(
		&(cmd_info->args[i]),
		_strdup(convert_number(cmd_info->status, 10, 0))
	);
	continue;
	}
	if (!_strcmp(cmd_info->args[i], "$$"))
	{
	rep_str(&(cmd_info->args[i]), _strdup(convert_number(getpid(), 10, 0)));
	continue;
	}
	node = node_starts_with(cmd_info->env, &cmd_info->args[i][1], '=');
	if (node)
	{
	rep_str(&(cmd_info->args[i]), _strdup(_strchr(node->str, '=') + 1));
	continue;
	}
	rep_str(&cmd_info->args[i], _strdup(""));
	}
	return (0);
}

/**
 * rep_str - replaces string
 * @old_str: address of old string
 * @new_str: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int rep_str(char **old_str, char *new_str)
{
	free(*old_str);
	*old_str = new_str;
	return (1);
}
