#include "shell.h"

/**
 **_eppu - prints a string of input.
 ** @str: a string that will be printed.
 ** Return: Nothing.
 **/
void _eppu(char *str)
{
int v = 0;

if (!str)
return;
while (str[v] != '\0')
{
_epitch(str[v]);
v++;
}
}

/**
 ** _epitch - adds the letter C to stderr.
 ** @c: The text to be printed.
 ** Return: Regarding achievement 1.
 ** On error, Errno is set appropriately and a value of -1 is returned.
 **/
int _epitch(char c)
{
static int v;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
{
write(2, buf, v);
v = 0;
}
if (c != BUF_FLUSH)
buf[v++] = c;
return (1);
}

/**
 ** _puiuf - writes the letter C to the specified fd.
 ** @c: The text to be printed.
 ** @fd: The address to write to is.
 ** Return: Regarding achievement 1.
 ** On error, Errno is set appropriately and a value of -1 is returned.
 **/
int _puiuf(char c, int fd)
{
static int v;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
{
write(fd, buf, v);
v = 0;
}
if (c != BUF_FLUSH)
buf[v++] = c;
return (1);
}

/**
 **_puqsd - prints a string of input
 ** @str: a string that will be printed.
 ** @fd: The address to contact is.
 ** Return: amount of characters entered.
 */
int _puqsd(char *str, int fd)
{
int v = 0;

if (!str)
return (0);
while (*str)
{
v += _puiuf(*str++, fd);
}
return (v);
}
