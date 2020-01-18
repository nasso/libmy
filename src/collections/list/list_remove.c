/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"
#include "collections/list_priv.h"

void *list_remove(list_t *self, size_t i)
{
    void *val = NULL;
    list_node_t *head = self->head;

    if (i >= self->len)
        return (NULL);
    self->head = list__get_nth_node(head, i);
    if (self->head == head)
        head = head->next == head ? NULL : head->next;
    val = list_pop_front(self);
    self->head = head;
    return (val);
}
