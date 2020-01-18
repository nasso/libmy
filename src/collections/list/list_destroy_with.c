/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "collections/list.h"

void list_destroy_with(list_t *self, list_for_each_fn_t *fn, void *user_data)
{
    list_for_each(self, fn, user_data);
    list_destroy(self);
}
