#include "shell.h"

/**
 ** adn_nod - adds a node to the list's beginning.
 ** @head: address of the head node pointer.
 ** @str: field of node str.
 ** @num: History's node index.
 * Return: length of list.
*/
list_t *adn_nod(list_t **head, const char *str, int num)
{
list_t *ne_head;

if (!head)
return (NULL);
ne_head = malloc(sizeof(list_t));
if (!ne_head)
return (NULL);
_memfill((void *)ne_head, 0, sizeof(list_t));
ne_head->num = num;
if (str)
{
ne_head->str = _strtpp(str);
if (!ne_head->str)
{
free(ne_head);
return (NULL);
}
}
ne_head->next = *head;
*head = ne_head;
return (ne_head);
}

/**
 ** adn_no_ed - adds a node to the list's end.
 ** @head: address of the head node pointer.
 ** @str: field of node str.
 ** @num: History's node index.
 ** Return: length of list.
 */
list_t *adn_no_ed(list_t **head, const char *str, int num)
{
list_t *new_node, *node;

if (!head)
return (NULL);

node = *head;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memfill((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strtpp(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
for (; node && node->next; node = node->next)
;
if (node)
node->next = new_node;
else
*head = new_node;
return (new_node);
}


/**
 ** prin_li_st - only outputs a list_t linked list's str element.
 ** @h: reference to the root node.
 ** Return: length of list.
 **/
size_t prin_li_st(const list_t *h)
{
size_t v = 0;

for (; h; h = h->next)
{
_puuss(h->str ? h->str : "(nil)");
_puuss("\n");
v++;
}
return (v);
}



/**
 ** rm_nod_a_ind - removes a node at a specified index.
 ** @head: address of the initial node's pointer.
 ** @index: index of the deleted node.
 ** Return: 1 for success and 0 for failure.
 **/
int rm_nod_a_ind(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int v;

	if (!head || !*head)
		return (0);

	if (index == 0)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}

	prev_node = *head;
	node = prev_node->next;
	for (v = 1; node; v++)
	{
		if (v == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		prev_node = node;
		node = node->next;
	}

	return (0);
}

/**
 ** frre_lis - releases every node on a list.
 ** @head_ptr: address of the head node pointer.
 ** Return: void.
 **/
void frre_lis(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	for (node = head; node; node = next_node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
	}
	*head_ptr = NULL;
}

