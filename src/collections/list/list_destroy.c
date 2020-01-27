/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stddef.h>
#include "my/my.h"
#include "my/collections/list.h"

void list_destroy(list_t *self)
{
    list_node_t *node = self->head;
    list_node_t *next = NULL;

    if (node != NULL) {
        node->previous->next = NULL;
        while (node != NULL) {
            next = node->next;
            my_free(node);
            node = next;
        }
    }
    my_free(self);
}

void list_destroy_with(list_t *self, list_iter_fn_t *destroyer, void *user_data)
{
    if (destroyer != NULL)
        list_for_each(self, destroyer, user_data);
    list_destroy(self);
}
