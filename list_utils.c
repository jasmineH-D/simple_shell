#include "shell.h"

/**
 ** lis_lens - specifies the linked list's length.
 ** @h: reference to the root node.
 ** Return: length of list.
 **/
size_t lis_lens(const list_t *h)
{
size_t v = 0;

for (; h; h = h->next)
v++;

return (v);
}


/**
 ** liis_t_str - returns a list of strings using the list->str method.
 ** @head: reference to the root node.
 ** Return: multiple strings.
 **/
char **liis_t_str(list_t *head)
{
list_t *node = head;
size_t v = lis_lens(head), j;
char **strs;
char *str;

if (!head || !v)
return (NULL);

strs = malloc(sizeof(char *) * (v + 1));
if (!strs)
return (NULL);

v = 0;
while (node)
{
str = malloc(_stles(node->str) + 1);
if (!str)
{
for (j = 0; j < v; j++)
free(strs[j]);
free(strs);
return (NULL);
}

str = _stcop(str, node->str);
strs[v] = str;
node = node->next;
v++;
}

strs[v] = NULL;
return (strs);
}



/**
 ** prii_liss - displays all of a list_t linked list's components.
 ** @h: reference to the root node.
 ** Return: length of list.
 **/
size_t prii_liss(const list_t *h)
{
size_t v = 0;

for (; h; h = h->next, v++)
{
_puuss(convert_snum(h->num, 10, 0));
_puuchi(':');
_puuchi(' ');
_puuss(h->str ? h->str : "(nil)");
_puuss("\n");
}

return (v);
}

/**
 ** nodd_st_wi - yields a node whose string prefixes.
 ** @node: index of the list's head.
 ** @prefix: string matching.
 ** @c: the character after the prefix that will match.
 ** Return: match null or nodes.
 */
list_t *nodd_st_wi(list_t *node, char *prefix, char c)
{
char *p = NULL;

for (; node; node = node->next)
{
p = stres_wi(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
}

return (NULL);
}

/**
 ** gett_nodd_in - retrieves a node's index.
 ** @head: index of the list's head.
 ** @node: identifier of the node.
 ** Return: node index, or -1.
 **/
ssize_t gett_nodd_in(list_t *head, list_t *node)
{
size_t v = 0;

for (; head; head = head->next, v++)
{
if (head == node)
return (v);
}

return (-1);
}
