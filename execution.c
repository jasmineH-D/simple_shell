#include "shell.h"

/**
 * hsh - main general shell loop.
 * @info: information struct parameters and returns.
 * @av: the main() argument vector.
 *
 * Return: One for triumphs, zero for mistakes, or an error code.
 */
int hsh(info_t *info, char **av)
{
ssize_t r = 0;
int builtin_ret = 0;

while (r != -1 && builtin_ret != -2)
{
cledel_inf(info);
if (active(info))
_puuss("$ ");
_epitch(BUF_FLUSH);
r = gets_inp(info);
if (r != -1)
{
sett_inf(info, av);
builtin_ret = findloc_builtinco(info);
if (builtin_ret == -1)
find_command(info);
}
else if (active(info))
_puuchi('\n');
fr_inf(info, 0);
}
writecre_apphistory(info);
fr_inf(info, 1);
if (!active(info) && info->status)
exit(info->status);
if (builtin_ret == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (builtin_ret);
}

/**
 * findloc_builtinco - identifies a built-in command.
 * @info: information struct for parameters and returns.
 * Return: -1 if a built-in cannot be discovered,
 *			0 if the builtin was successfully run,
 *			if a built-in is found but not used,
 *			If built-in signals exit(), it is -2.
 */
int findloc_builtinco(info_t *info)
{
int i, buuilt_i_re = -1;
biltin_tale bultintl[] = {
{"exit", _miex},
{"env", _mievv},
{"help", _mihely},
{"history", _myhist},
{"setenv", _miserevv},
{"unsetenv", _miunsotevv},
{"cd", _micedd},
{"alias", _myhelpalias},
{NULL, NULL}
};

for (i = 0; bultintl[i].type; i++)
if (_stcmm(info->argv[0], bultintl[i].type) == 0)
{
info->line_count++;
buuilt_i_re = bultintl[i].func(info);
break;
}
return (buuilt_i_re);
}

/**
 * find_command - search for a command in PATH.
 * @info: information struct for parameters and returns.
 * Return: void.
 */
void find_command(info_t *info)
{
char *path = NULL;
int i, k;

info->path = info->argv[0];
if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}
for (i = 0, k = 0; info->arg[i]; i++)
if (!ist_de(info->arg[i], " \t\n"))
k++;
if (!k)
return;

path = fed_putt(info, _geevv(info, "PATH="), info->argv[0]);
if (path)
{
info->path = path;
fork_command(info);
}
else
{
if ((active(info) || _geevv(info, "PATH=")
|| info->argv[0][0] == '/') && is_comdd(info, info->argv[0]))
fork_command(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
print_errorms(info, "not found\n");
}
}
}

/**
 * fork_command - runs cmd after forking an exec thread.
 * @info: information struct for parameters and returns.
 * Return: void.
 */
void fork_command(info_t *info)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{

perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(info->path, info->argv, cp_evviron_str(info)) == -1)
{
fr_inf(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}

}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
print_errorms(info, "Permission denied\n");
}
}
}
