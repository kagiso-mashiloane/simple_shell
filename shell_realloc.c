#include "shell.h"

/**
 * _memset_custom - Fills the first @num_bytes
 * of the memory area pointed to by @dest with
 * the constant byte @byte_val.
 * @dest: A pointer to the destination memory.
 * @byte_val: The value to be set in each byte
 * of the destination memory.
 * @num_bytes: The number of bytes to set in
 * the destination memory.
 * Return: A pointer to the destination memory.
 */
char *_memset_custom(char *dest, char byte_val,
	unsigned int num_bytes)
{
	unsigned int i;

	for (i = 0; i < num_bytes; i++)
		dest[i] = byte_val;
	return (dest);
}

/**
 * ffree_custom - Frees the memory allocated
 * for an array of strings.
 * @str_array: A pointer to an array of strings.
 */
void ffree_custom(char **str_array)
{
	char **temp_ptr = str_array;

	if (!str_array)
		return;
	while (*str_array)
		free(*str_array++);
	free(temp_ptr);
}

/**
 * _realloc_custom - Resizes a previously
 * allocated memory block.
 * @prev_ptr: A pointer to the previously
 * allocated memory.
 * @prev_size: The size of the previously
 * allocated memory block.
 * @new_size: The new size to which the
 * memory block should be resized.
 * Return: A pointer to the resized memory
 * block, or NULL on failure.
 */
void *_realloc_custom(void *prev_ptr,
unsigned int prev_size, unsigned int new_size)
{
	char *new_ptr;

	if (!prev_ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(prev_ptr), NULL);
	if (new_size == prev_size)
		return (prev_ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	prev_size = prev_size < new_size ? prev_size : new_size;
	while (prev_size--)
		new_ptr[prev_size] = ((char *)prev_ptr)[prev_size];
	free(prev_ptr);
	return (new_ptr);
}
