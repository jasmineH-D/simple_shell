#include "shell.h"

/**
 * **sttiww - makes word divisions in a string. It ignores repeated delimiters.
 * @str: input string
 * @d: delimeter string
 * Return: a pointer to a string array, or NULL in the event of failure.
 */

char **sttiww(char *str, char *d)
{
int i, j, k, m, nuuworr = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (i = 0; str[i] != '\0'; i++)
if (!ist_de(str[i], d) && (ist_de(str[i + 1], d) || !str[i + 1]))
nuuworr++;

if (nuuworr == 0)
return (NULL);
s = malloc((1 + nuuworr)*sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < nuuworr; j++)
{

while (ist_de(str[i], d))
i++;
k = 0;
while (!ist_de(str[i + k], d) && str[i + k])
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{

for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);

}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

/**
 * **sttiw2 - separates words from a string
 * @str: input string
 * @d: delimeter
 * Return: a pointer to a string array, or NULL in the event of failure
 */

char **sttiw2(char *str, char d)
{
int i, j, k, m, nuuworr = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
nuuworr++;
if (nuuworr == 0)
return (NULL);
s = malloc((1 + nuuworr)*sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < nuuworr; j++)
{
while (str[i] == d && str[i] != d)
i++;
k = 0;
while (str[i + k] != d && str[i + k] && str[i + k] != d)
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}

s[j] = NULL;
return (s);
}
