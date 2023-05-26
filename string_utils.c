#include "shell.h"

/**
 * _stcop - copy string
 * @dest: destination
 * @src: source
 * Return: pointer to destination
 */

char *_stcop(char *dest, char *src)
{
int v = 0;

if (dest == src || src == 0)
return (dest);
while (src[v])
{
dest[v] = src[v];
v++;
}
dest[v] = 0;
return (dest);
}

/**
 * _strtpp - duplicate string
 * @str: duplicate strings
 * Return: string reference to the replicate text
 */

char *_strtpp(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 *_puuss - print an input string
 *@str: string to be printed
 * Return: nothing
 */

void _puuss(char *str)
{
int v = 0;

if (!str)
return;
while (str[v] != '\0')
{
_puuchi(str[v]);
v++;
}
}

/**
 * _puuchi - write char c to stdout
 * @c: char to print
 * Return: 1. * If everything goes well,
 *  -1 is returned, and errno is set accordingly.
 */
int _puuchi(char c)
{
static int v;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
{
write(1, buf, v);
v = 0;
}
if (c != BUF_FLUSH)
buf[v++] = c;
return (1);
}
