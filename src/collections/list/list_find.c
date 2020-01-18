/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"
#include "collections/list_priv.h"

void *list_find(list_t *self, list_find_fn_t *fn, void *user_data)
{
    list_node_t *node = self->head;

    if (node == NULL)
        return (NULL);
    for (size_t i = 0; i < self->len; i++) {
        if (fn(user_data, node->val) == 0)
            return (node->val);
        node = node->next;
    }
    return (NULL);
}
