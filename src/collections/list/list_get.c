/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "my/types.h"
#include "my/collections/list.h"
#include "my/collections/list_priv.h"

OPT(ptr) list_get(const list_t *ls, usize_t i)
{
    if (i >= ls->len)
        return (NONE(ptr));
    return (SOME(ptr, list__get_nth_node(ls->head, i)->val));
}
