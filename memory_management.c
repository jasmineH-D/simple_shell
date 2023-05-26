#include "shell.h"

/**
 * frnpr - NULLizes the address and releases a pointer.
 * @ptr: address of the free pointer.
 * Return: If released, 1; otherwise, 0.
*/
int frnpr(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
