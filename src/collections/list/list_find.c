/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "types.h"
#include "collections/list.h"
#include "collections/list_priv.h"

void *list_find_with(list_t *self, list_iter_fn_t *fn, void *element)
{
    list_node_t *node = self->head;

    if (node == NULL)
        return (NULL);
    for (usize_t i = 0; i < self->len; i++) {
        if (fn ? !fn(element, node->val) : (element == node->val))
            return (node->val);
        node = node->next;
    }
    return (NULL);
}

void *list_find(list_t *self, void *element)
{
    return (list_find_with(self, NULL, element));
}
