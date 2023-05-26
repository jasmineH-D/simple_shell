#include "shell.h"

/**
 * is_chain - check to see if the current char in the bufes is a chain delimete
 * @info: parameter struct
 * @buf: char buffers
 * @p: current buffer position's address
 * Return: Chain delimeter: 1; otherwise, 0
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
size_t j = *p;

if (buf[j] == '|' && buf[j + 1] == '|')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[j] == '&' && buf[j + 1] == '&')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[j] == ';')
{
buf[j] = 0;
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = j;
return (1);
}

/**
 * cheok_cha - based on the most recent status, determine whet chain checks
 * @info: parameter struct
 * @buf: char buffer
 * @p: current buffer position's address
 * @v: start position in buffer
 * @len: length of buffer
 * Return: Void
 */

void cheok_cha(info_t *info, char *buf, size_t *p, size_t v, size_t len)
{
size_t j = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[v] = 0;
j = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[v] = 0;
j = len;
}
}

*p = j;
}

/**
 * replace_alias - in the tokenized string, swap out an alias.
 * @info: parameter struct
 * Return: 1 if replaced, 0 otherwise
 */

int replace_alias(info_t *info)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
node = nodd_st_wi(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _fidchr(node->str, '=');
if (!p)
return (0);
p = _strtpp(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}


/**
 * replace_vars - replaces vars in the tokenized string
 * @info: parameter struct
 * Return: 1 if replaced, 0 otherwise
 */

int replace_vars(info_t *info)
{
int v = 0;
list_t *node;

while (info->argv[v])
{
if (info->argv[v][0] != '$' || !info->argv[v][1])
{
v++;
continue;
}

if (!_stcmm(info->argv[v], "$?"))
{
replace_string(&(info->argv[v]),
_strtpp(convert_snum(info->status, 10, 0)));
v++;
continue;
}
if (!_stcmm(info->argv[v], "$$"))
{
replace_string(&(info->argv[v]), _strtpp(convert_snum(getpid(), 10, 0)));
v++;
continue;
}

node = nodd_st_wi(info->env, &info->argv[v][1], '=');
if (node)
{
replace_string(&(info->argv[v]), _strtpp(_fidchr(node->str, '=') + 1));
}
else
{
replace_string(&info->argv[v], _strtpp(""));
}

v++;
}

return (0);
}


/**
 * replace_string - replace string
 * @old: address of old string
 * @new: new string
 * Return: 1 if replaced, 0 otherwise
 */

int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
