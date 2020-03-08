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
    int err = 0;

    LIST_FOR_EACH_AND(self, iter, err == 0)
        err = fn(element, iter.v);
    return (err);
}
