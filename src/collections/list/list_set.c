/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"
#include "collections/list_priv.h"

int list_set(list_t *ls, size_t i, void *data)
{
    if (i >= ls->len)
        return (-1);
    list__get_nth_node(ls->head, i)->val = data;
    return (0);
}
