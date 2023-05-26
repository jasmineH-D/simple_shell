#include "shell.h"

/**
 * is_comdd - tests a file to see if it is an executable command
 * @info: data structure.
 * @path: url of the file.
 * Return: 0 if false, 1 if true.
 **/
int is_comdd(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 ** da_ch - characters with duplicates.
 ** @pathstr: PATH is a string.
 ** @start: beginning index.
 ** @stop: halting index.
 ** Return: pointing to a new file.
 **/
char *da_ch(char *pathstr, int start, int stop)
{
static char buf[1024];
int v = 0, k = 0;

for (k = 0, v = start; v < stop; v++)
if (pathstr[v] != ':')
buf[k++] = pathstr[v];
buf[k] = 0;
return (buf);
}

/**
 ** fed_putt - the PATH string identifies this command.
 ** @info: data structure.
 ** @pathstr: PATH is a string.
 ** @cmd: a command to use.
 ** Return: complete path of the command, if found, or NULL.
 **/
char *fed_putt(info_t *info, char *pathstr, char *cmd)
{
int v, curr_pos = 0;
char *path;

if (!pathstr)
return (NULL);

if ((_stles(cmd) > 2) && stres_wi(cmd, "./"))
{
if (is_comdd(info, cmd))
return (cmd);
}

for (v = 0; ; v++)
{
if (!pathstr[v] || pathstr[v] == ':')
{
path = da_ch(pathstr, curr_pos, v);
if (!*path)
_stcet(path, cmd);
else
{
_stcet(path, "/");
_stcet(path, cmd);
}
if (is_comdd(info, path))
return (path);
if (!pathstr[v])
break;
curr_pos = v;
}
}

return (NULL);
}
