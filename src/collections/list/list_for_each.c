/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"

void list_for_each(list_t *self, list_for_each_fn_t *fn, void *user_data)
{
    list_node_t *node = self->head;

    if (node == NULL)
        return;
    for (size_t i = 0; i < self->len; i++) {
        if (fn(user_data, node->val))
            return;
        node = node->next;
    }
}
