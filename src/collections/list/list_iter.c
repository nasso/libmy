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
    list_iter_t iter = {0};

    iter.i = 0;
    iter.total = self->len;
    iter.next = self->head ? self->head->next : NULL;
    iter.v = iter.total > 0 ? self->head->val : NULL;
    return (iter);
}

bool list_iter_ended(const list_iter_t *iter)
{
    return (iter->i >= iter->total);
}

void list_iter_next(list_iter_t *iter)
{
    iter->i++;
    if (iter->i < iter->total) {
        iter->v = iter->next->val;
        iter->next = iter->next->next;
    }
}
