/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stddef.h>
#include "my/types.h"
#include "my/collections/list.h"

int list_for_each(list_t *self, list_iter_fn_t *fn, void *element)
{
    list_node_t *node = self->head;
    int err = 0;

    if (node == NULL)
        return (err);
    for (usize_t i = 0; !err && i < self->len; i++) {
        err = fn(element, node->val);
        node = node->next;
    }
    return (err);
}
