/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"
#include "collections/list_priv.h"

int list_insert(list_t *self, size_t i, void *data)
{
    int err = 0;
    list_node_t *head = self->head;

    if (i > self->len)
        return (0);
    self->head = list__get_nth_node(head, i % self->len);
    err = list_push_back(self, data);
    self->head = head;
    return (err);
}