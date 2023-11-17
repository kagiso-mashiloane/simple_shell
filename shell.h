#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CONVERT_TO_LOWERCASE
#define CONVERT_TO_UNSIGNED
#define HISTORY_FILE	".simple_shell_history"
#define HISTORY_MAX	4096
#define CMDL_NORM
#define CMDL_OR
#define CMDL_AND
#define CMDL_CHAIN


/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @num: integer
 * @next: points to the next node
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	int num;
	struct list_s *next;
} list_t;

/**
 * struct passinfo - Structure to hold information for command execution.
 * @arg: Pointer to a character string representing an argument.
 * @argv: Pointer to an array of strings representing command-line arguments.
 * @path: Pointer to a character string representing a file path.
 * @argc: Number of command-line arguments.
 * @line_count: Unsigned integer representing the line count.
 * @err_num: Integer representing an error number.
 * @linecount_flag: Integer flag indicating whether line counting is enabled.
 * @fname: Pointer to a character string representing a file name.
 * @env: Pointer to a linked list structure representing environment variables.
 * @history: Pointer to a linked list structure representing command history.
 * @alias: Pointer to a linked list structure representing command aliases.
 * @environ: Pointer to an array of strings representing the environment.
 * @env_changed: Integer flag indicating whether the environment has changed.
 * @status: Integer representing the status.
 * @cmd_buf: Pointer to an array of strings representing command buffer.
 * @cmd_buf_type: Integer representing the type of command buffer.
 * @readfd: Integer representing the read file descriptor.
 * @histcount: Integer representing the command history count.
 */
typedef struct passinfo
{
	char *args;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;
void _dputs(char *);
int _dputchar(char);
int _dputfd(char c, int fd);
int _dputsfd(char *str, int fd);
char *_strcatt(char *, char *);
char *_strcpyy(char *, char *);
int my_strlen(char *);
int my_strcmp(char *, char *);
char *my_strdup(const char *);
char *my_strchr(char *, char);
int is_delimeter(char a, char *delimeter);
int interactive_mode(info_t *infomation);
int _isalphabet(int k);
int _atoi(char *str);
int helpinfo_shell(info_t *information);
int change_c_directory(info_t *information);
int exit_ssh(info_t *infomation);
int _myaliases(info_t *information);
int sets_alias(info_t *information, char *ptr);
int unsets_alias(info_t *information, char *ptr);
int _prints_alias(list_t *node);
char *getValueOfEnvVar(info_t *information, const char *var_name);
int printEnvironment(info_t *information);
int initializeEnvVar(info_t *information);
int populateEnvironmentList(info_t *information);
int removeEnvVar(info_t *info_Struct, char *varName);
void printErrorString(char *string);
int putCharacterToFD(char d, int fd);
int printErrorCharacter(char a);
int printStringToFD(char *strr, int fd);
int error_atoi(char *c);
int print_dec(int num, int fd);
void prints_error(info_t *information, char *str);
char *num_converter(long int numb, int _base, int flagss);
void delete_comments(char *buff);
char *find_character(char *ptr, char character);
char *string_concatenator(char *str1, char *str2, int num_bytes);
char *string_copier(char *destination, char *source, int num_chars);
char **getEnvironment(info_t *info_Struct);
int setEnvVar(info_t *infoStruct, char *varName, char *value);
int removeEnvVar(info_t *info_Struct, char *varName);
void clears_information(info_t *information);
void sets_information(info_t *information, char **av);
int renumbers_history(info_t *info);
char *gets_history_files(info_t *info);
int writes_history(info_t *info);
int reads_history(info_t *info);
int builds_history_list(info_t *info, char *buff, int line_count);
int get_next_line(info_t *info, char **buffer, size_t *buffer_size);
ssize_t input_buffer(info_t *information, char **buffer, size_t *length);
ssize_t gets_input(info_t *information);
ssize_t read_buffer(info_t *information, char *buffer, size_t *s);
void signalntHandler(__attribute__((unused))int signalnum);

int is_cmd(info_t *cmd_info, char *cmd_buf, size_t *pos);
void chk_cmd(info_t *cmd_info, char *cmd_buf,
size_t *pos, size_t start_pos, size_t len);
int rep_alias(info_t *cmd_info);
int rep_vars(info_t *cmd_info);
int rep_str(char **old_str, char *new_str);
char **splitStr(char *s, char *d);
char **splitStr2(char *s, char d);
char *copy_str(char *dest, char *src);
char *str_duplicate(const char *src);
void put_str(char *str);
int put_char(char c);
int str_length(char *str);
int str_compare(char *str1, char *str2);
char *str_starts_with(const char *str,
	const char *substring);
char *str_concat(char *result_buffer,
	char *source_buffer);
int shell(info_t *si, char **args);
int bshell(info_t *si);
void cmdfind(info_t *si);
void forkcmd(info_t *si);
char *_memset_custom(char *dest, char byte_val,
	unsigned int num_bytes);
void ffree_custom(char **str_array);
void *_realloc_custom(void *prev_ptr,
unsigned int prev_size, unsigned int new_size);
int is_exec(info_t *i, char *p);
char *dup_ch(char *ps, int s, int e);
char *find_p(info_t *i, char *ps, char *c);
int customFree(void **target_ptr);
int main(int argc, char **argv);
size_t len(const list_t *current);
char **to_strings(list_t *first);
size_t print(const list_t *first);
list_t *sw_node(list_t *start, char *prefix, char c);
ssize_t index_node(list_t *first, list_t *c_node);
list_t *add(list_t **h, const char *s, int n);
list_t *add_end(list_t **h, const char *s, int n);
size_t print_str(const list_t *n);
int delete_at_index(list_t **h, unsigned int index);
void free_list(list_t **h);

#endif

