#include "shell.h"

/**
 **_cpsrting - duplicates a string.
 *@dest: the string to be copied to at the destination.
 *@src: the original string.
 *@n: how many characters will be duplicated.
 *Return: the string that has been joined.
 */
char *_cpsrting(char *dest, char *src, int n)
{
char *s = dest;
int v = 0;

while (src[v] != '\0' && v < n - 1)
{
dest[v] = src[v];
v++;
}

if (v < n)
{
int j = v;
while (j < n)
{
dest[j] = '\0';
j++;
}
}

return (s);
}

/**
 **_copncatsr - joins two strings together.
 *@dest: the opening string.
 *@src: the backup group.
 *@n: the backup group.
 *Return: the string that has been joined.
 */
char *_copncatsr(char *dest, char *src, int n)
{
char *s = dest;
int v = 0;
int j = 0;

while (dest[v] != '\0')
{
v++;
}

while (src[j] != '\0' && j < n)
{
dest[v + j] = src[j];
j++;
}

if (j < n)
{
dest[v + j] = '\0';
}

return (s);
}

/**
 **_fidchr - seeks out a character within a string.
 *@s: to be parsed is the string.
 *@c: the person to watch out for.
 *Return: (s) a reference to the memory location s.
 */
char *_fidchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}

return (NULL);
}
