#include "shell.h"
/**
 * customFree - Frees the memory allocated for
 * a pointer and sets it to NULL.
 * @target_ptr: A pointer to a pointer whose
 * memory needs to be freed.
 * This function frees the memory allocated
 * for the pointer referenced by
 * target_ptr and sets the pointer to NULL
 * to avoid double freeing.
 * Return: 1 on success, 0 on failure .
 **/
int customFree(void **target_ptr)
{
	if (target_ptr && *target_ptr)
	{
		free(*target_ptr);
		*target_ptr = NULL;
		return (1);
	}
	return (0);
}
