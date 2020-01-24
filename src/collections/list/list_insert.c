/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "my/collections/list.h"
#include "my/collections/list_priv.h"

bool list_insert(list_t *self, usize_t i, void *data)
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
