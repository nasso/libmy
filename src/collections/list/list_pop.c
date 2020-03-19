/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "my/collections/list.h"
#include "my/collections/list_priv.h"

void *list_pop_front(list_t *self)
{
    void *val = NULL;

    if (self->head == NULL)
        return (NULL);
    self->head = self->head->next;
    val = list_pop_back(self);
    return (val);
}

void *list_pop_back(list_t *self)
{
    void *val = NULL;

    if (self->head == NULL)
        return (NULL);
    val = list__destroy_node(&self->cache, self->head->previous);
    self->len--;
    if (self->len == 0)
        self->head = NULL;
    return (val);
}
