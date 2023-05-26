#include "shell.h"

/**
 * get_histret_fi - obtaining the history file.
 * @info: variable struct.
 * Return: history file in the allocated string.
 */

char *get_histret_fi(info_t *info)
{
char *buf, *der;

der = _geevv(info, "HOME=");
if (!der)
return (NULL);
buf = malloc(sizeof(char) * (_stles(der) + _stles(HIST_FILE) + 2));
if (!buf)
return (NULL);
buf[0] = 0;
_stcop(buf, der);
_stcet(buf, "/");
_stcet(buf, HIST_FILE);
return (buf);
}

/**
 * writecre_apphistory - creates a fi one th alr exi.
 * @info: the struct of parameters.
 * Return: 1 upon success, -1 otherwise.
 */
int writecre_apphistory(info_t *info)
{
ssize_t fd;
char *filename = get_histret_fi(info);
list_t *node = NULL;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_puqsd(node->str, fd);
_puiuf('\n', fd);
}
_puiuf(BUF_FLUSH, fd);
close(fd);
return (1);
}

/**
 * red_hist - s file history to be read.
 * @info: the struct of parameters.
 * Return: if successful, histcount; otherwise, 0.
 */
int red_hist(info_t *info)
{
int i, last = 0, linecount = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = get_histret_fi(info);

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buf = malloc(sizeof(char) * (fsize + 1));
if (!buf)
return (0);
rdlen = read(fd, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
return (free(buf), 0);
close(fd);
for (i = 0; i < fsize; i++)
if (buf[i] == '\n')
{
buf[i] = 0;
bud_addhs_ls(info, buf + last, linecount++);
last = i + 1;
}
if (last != i)
bud_addhs_ls(info, buf + last, linecount++);
free(buf);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
rm_nod_a_ind(&(info->history), 0);
rem_his(info);
return (info->histcount);
}

/**
 * bud_addhs_ls - creates a new entry in a history-linked list.
 * @info: Arrangement with potential arguments. used to keep up.
 * @buf: bufs
 * @linecount: the linecount of history, histcount.
 * Return: never 1.
 */
int bud_addhs_ls(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
adn_no_ed(&node, buf, linecount);

if (!info->history)
info->history = node;
return (0);
}

/**
 * rem_his - after revisions, the history linked list is renumbered.
 * @info: Arrangement with potential arguments. used to keep up.
 * Return: the updated headcount.
 */
int rem_his(info_t *info)
{
list_t *node = info->history;
int i = 0;

while (node)
{
node->num = i++;
node = node->next;
}
return (info->histcount = i);
}
