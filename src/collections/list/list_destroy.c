/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stddef.h>
#include "my.h"
#include "collections/list.h"

void list_destroy(list_t *self)
{
    list_node_t *node = self->head;
    list_node_t *next = NULL;

    if (node == NULL)
        return;
    node->previous->next = NULL;
    while (node != NULL) {
        next = node->next;
        my_free(node);
        node = next;
    }
    my_free(self);
}