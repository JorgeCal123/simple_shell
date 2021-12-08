#include "hsh.h"
/**
 * add_node - Description
 * @head: D
 * @arg:
 * Return:
 */

args_t *add_node(args_t **head, char* arg)
{
	args_t *node,  *aux;

	aux = *head;

	if(arg == NULL)
		return (NULL);

	node = malloc(sizeof(args_t));
	if(node == NULL)
		return (NULL);

	node->arg = arg;
	node->next = NULL;

	if(*head == NULL)
	{
	*head = node;
	return (node);
	}

	while(aux->next)
		aux = aux->next;

	aux->next = node;

	return (aux);
}


size_t print_list(const args_t *h)
{
	size_t elements = 0;

	while (h != NULL)
	{
		printf("%s\n", h->arg);
		h = h->next;
		elements++;
	}
	return (elements);
}


size_t size_list(const args_t *h)
{
        size_t elements = 0;

        while (h != NULL)
        {
                h = h->next;
                elements++;
        }
        return (elements);
}
