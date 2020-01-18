/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Private linked list functions implementation
*/

#include <stddef.h>
#include "my.h"
#include "collections/list.h"
#include "collections/list_priv.h"

list_node_t *list__create_node(void *data)
{
    list_node_t *node = my_malloc(sizeof(list_node_t));

    if (node == NULL)
        return (NULL);
    node->val = data;
    node->next = node;
    node->previous = node;
    return (node);
}
