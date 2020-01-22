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

void *list_get(const list_t *ls, usize_t i)
{
    if (i >= ls->len)
        return (NULL);
    return (list__get_nth_node(ls->head, i)->val);
}
