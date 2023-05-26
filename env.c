#include "shell.h"

/**
 * _mievv - print current enviroment
 * @info: structure containing potential argu
 * Return: 0
*/

int _mievv(info_t *info)
{
list_t *current = info->env;

for (; current != NULL; current = current->next)
{
_puuss(current->str);
_puuchi('\n');
}

return (0);
}

/**
 * _geevv - get value of an environ variable
 * @info: arrangment with possible arguments used to keep up
 * @name: env var name
 * Return: value
 */

char *_geevv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

for (; node != NULL; node = node->next)
{
p = stres_wi(node->str, name);
if (p && *p)
return (p);
}

return (NULL);
}
/**
 * _miserevv - initialize  new environment variable
 *             or modify an existing one
 * @info: Arrangement with possible arguments.
 *  used to retain the prototype of the * constant function.
 *  Return: Always 0
 */

int _miserevv(info_t *info)
{
if (info->argc != 3)
{
_eppu("Incorrect number of arguments\n");
return (1);
}
if (_initenva(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}


/**
 * _miunsotevv - Remove an environment variable
 * @info: Arrangement with possible arguments.
 *  used to retain the prototype of the * constant function.
 *  Return: 0
 */

int _miunsotevv(info_t *info)
{
int v;

if (info->argc == 1)
{
_eppu("Too few arguments.\n");
return (1);
}

for (v = 1; v < info->argc; v++)
_rmunsetenv(info, info->argv[v]);

return (0);
}

/**
 * populate_evv_li - fills in the env linked list
 * @info: Arrangement with possible arguments.
 *  used to retain the prototype of the * constant function.
 * Return: 0
 */

int populate_evv_li(info_t *info)
{
list_t *node = NULL;
size_t v;

for (v = 0; environ[v]; v++)
adn_no_ed(&node, environ[v], 0);
info->env = node;

return (0);
}
