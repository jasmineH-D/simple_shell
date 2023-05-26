#include "shell.h"

/**
 **_memfill - gives memory a constant byte of data.
 **@s: the memory area's pointer.
 **@b: the byte that *s should contain.
 **@n: the number of bytes that must be filled.
 **Return: (s) a reference to the memory location s.
 */
char *_memfill(char *s, char b, unsigned int n)
{
unsigned int v;

for (v = 0; v < n; v++)
s[v] = b;
return (s);
}

/**
 ** ffrre - releases a group of strings.
 ** @pp: strings of words.
 **/
void ffrre(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
 ** _reeloc - reallocates a memory block.
 ** @ptr: identifier of a previously malloc'd block.
 ** @od_si: Block size before in bytes.
 ** @nw_si: Block size in bytes.
 ** Return: reference to the old block nameen.
 **/
void *_reeloc(void *ptr, unsigned int od_si, unsigned int nw_si)
{
char *p;

if (!ptr)
return (malloc(nw_si));
if (!nw_si)
return (free(ptr), NULL);
if (nw_si == od_si)
return (ptr);

p = malloc(nw_si);
if (!p)
return (NULL);

od_si = od_si < nw_si ? od_si : nw_si;
while (od_si--)
p[od_si] = ((char *)ptr)[od_si];
free(ptr);
return (p);
}
