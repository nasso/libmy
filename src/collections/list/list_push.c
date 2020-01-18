/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"
#include "collections/list_priv.h"

int list_push_front(list_t *self, void *data)
{
    list_node_t *node = list__create_node(data);

    if (node == NULL)
        return (1);
    if (self->head)
        list__insert_before(self->head, node);
    self->head = node;
    self->len++;
    return (0);
}

int list_push_back(list_t *self, void *data)
{
    if (list_push_front(self, data))
        return (1);
    self->head = self->head->next;
    return (0);
}
