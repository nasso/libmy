/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"
#include "collections/list_priv.h"

void *list_get(const list_t *ls, size_t i)
{
    if (i >= ls->len)
        return (NULL);
    return (list__get_nth_node(ls->head, i)->val);
}
