/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** list_iter functions implementation
*/

#include "my/my.h"
#include "my/collections/list.h"

list_iter_t list_iter(const list_t *self)
{
    list_iter_t iter;

    iter.i = 0;
    iter.total = self->len;
    iter.node = self->head;
    if (iter.node)
        iter.v = iter.node->val;
    return (iter);
}

bool list_iter_ended(const list_iter_t *iter)
{
    return (iter->i >= iter->total);
}

void list_iter_next(list_iter_t *iter)
{
    if (iter->i < iter->total) {
        iter->i++;
        iter->node = iter->node->next;
        iter->v = iter->node->val;
    }
}