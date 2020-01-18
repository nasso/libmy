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

void *list__destroy_node(list_node_t *node)
{
    void *val = node->val;

    node->previous->next = node->next;
    node->next->previous = node->previous;
    my_free(node);
    return (val);
}
