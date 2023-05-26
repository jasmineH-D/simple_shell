#include "shell.h"

/**
 ** active - if the shell is in active mode, it returns true.
 ** @info: address in struct.
 ** Return: 1 if the mode is activated; 0 otherwise.
**/
int active(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 ** ist_de - determines whether a character is a delimeter.
 ** @c: a character to check.
 ** @deli: the string of delimeter.
 ** Return: 0 if false, 1 if true.
 **/
int ist_de(char c, char *deli)
{
while (*deli)
if (*deli++ == c)
return (1);
return (0);
}

/**
 **_isph - makes an alphabetic character check.
 **@c: The input character.
 **Return: 0 else, 1 if c is alphabetical.
 **/

int _isph(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 **_atii - creates an integer from a string.
 **@s: the string being transformed.
 **Return: 0 if the string contains no numbers,
 ** else, a converted number.
 **/

int _atii(char *s)
{
int v = 0, sign = 1, flag = 0, out;
unsigned int res = 0;

while (s[v] != '\0' && flag != 2)
{
if (s[v] == '-')
sign *= -1;

if (s[v] >= '0' && s[v] <= '9')
{
flag = 1;
res *= 10;
res += (s[v] - '0');
}
else if (flag == 1)
flag = 2;

v++;
}

if (sign == -1)
out = -res;
else
out = res;

return (out);
}

