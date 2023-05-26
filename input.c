#include "shell.h"

/**
 ** inp_bufff - chaed comm with buufe.
 ** @info: variable struct.
 ** @buf: place of business.
 ** @len: Location of Len Var.
 * Return: data read.
 */
ssize_t inp_bufff(info_t *info, char **buf, size_t *len)
{
ssize_t r = 0;
size_t len_p = 0;

if (!*len)
{
free(*buf);
*buf = NULL;
signal(SIGINT, sigHan);
#if USE_GETLINE
r = getline(buf, &len_p, stdin);
#else
r = _geli(info, buf, &len_p);
#endif
if (r > 0)
{
if ((*buf)[r - 1] == '\n')
{
(*buf)[r - 1] = '\0';
r--;
}
info->linecount_flag = 1;
replace_comments(*buf);
bud_addhs_ls(info, *buf, info->histcount++);

*len = r;
info->cmd_buf = buf;
}
}
return (r);
}

/**
 ** gets_inp - removes the newline from a line.
 ** @info: variable struct.
 ** Return: data read.
 **/
ssize_t gets_inp(info_t *info)
{
static char *buf;
static size_t v, j, len;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;

_puuchi(BUF_FLUSH);
r = inp_bufff(info, &buf, &len);
if (r == -1)
return (-1);
if (len)
{
j = v;
p = buf + v;

cheok_cha(info, buf, &j, v, len);
for (; j < len; j++)
{
if (is_chain(info, buf, &j))
break;
}

v = j + 1;
if (v >= len)
{
v = len = 0;
info->cmd_buf_type = CMD_NORM;
}

*buf_p = p;
return (_stles(p));
}

*buf_p = buf;
return (r);
}

/**
 * re_buuf - reads an article.
 * @info: variable struct.
 * @buf: buufs.
 * @v: si.
 *
 * Return: r.
 */
ssize_t re_buuf(info_t *info, char *buf, size_t *v)
{
ssize_t r = 0;

if (*v)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*v = r;
return (r);
}

/**
 ** _geli - obtains the following line of input from STDIN.
 ** @info: variable struct.
 ** @ptr: address of the bufes pointer, either preallocated or NULL.
 ** @length: if not NULL, the preallocated pointer buffer's size.
 ** Return: s.
 **/
int _geli(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t v, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;

p = *ptr;
if (p && length)
s = *length;
if (v == len)
v = len = 0;

r = re_buuf(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);

c = _fidchr(buf + v, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_p = _reeloc(p, s, s ? s + k : k + 1);
if (!new_p)
return (p ? free(p), -1 : -1);

if (s)
_copncatsr(new_p, buf + v, k - v);
else
_cpsrting(new_p, buf + v, k - v + 1);

s += k - v;
v = k;
p = new_p;

if (length)
*length = s;
*ptr = p;
return (s);
}

/**
 ** sigHan - ctrl-C stops.
 ** @sig_num: a signal's identr.
 ** Return: void.
 **/
void sigHan(__attribute__((unused))int sig_num)
{
_puuss("\n");
_puuss("$ ");
_puuchi(BUF_FLUSH);
}

