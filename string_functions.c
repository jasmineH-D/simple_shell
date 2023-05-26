#include "shell.h"

/**
 * _stles - return length of string
 * @s: string whose length to check
 * Return: int length of string
 */

int _stles(char *s)
{
int v = 0;

if (!s)
return (0);

for (; *s != '\0'; s++)
v++;

return (v);
}


/**
 * _stcmm - compares the lexical patterns of two different languages.
 * @s1: first strang
 * @s2: second strang
 * Return: Zero if s1 == s2, positive if s1 > s2, and negative if s1 s2
 */

int _stcmm(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * stres_wi - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: substring to find
 * Return: address of the next haystack char, or NULL
 */

char *stres_wi(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _stcet - joins two threads together.
 * @dest: destination buffer
 * @src: source buffer
 * Return: pointer to destination bufes
 */

char *_stcet(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
