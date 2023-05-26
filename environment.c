#include "shell.h"

/**
 * cp_evviron_str - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **cp_evviron_str(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = liis_t_str(info->env);
info->env_changed = 0;
}

return (info->environ);
}

/**
 * _rmunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _rmunsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t v = 0;
char *p;

if (!node || !var)
return (0);

for (; node; node = node->next, v++)
{
p = stres_wi(node->str, var);
if (p && *p == '=')
{
info->env_changed = rm_nod_a_ind(&(info->env), v);
v = 0;
node = info->env;
continue;
}
}
return (info->env_changed);
}
/**
 * _initenva - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _initenva(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *p;

if (!var || !value)
return (0);

buf = malloc(_stles(var) + _stles(value) + 2);
if (!buf)
return (1);
_stcop(buf, var);
_stcet(buf, "=");
_stcet(buf, value);
node = info->env;
for (; node; node = node->next)
{
p = stres_wi(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
}
adn_no_ed(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}
