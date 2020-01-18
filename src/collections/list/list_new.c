/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stddef.h>
#include "my.h"
#include "collections/list.h"

list_t *list_new(void)
{
    list_t *ls = my_malloc(sizeof(list_t));

    if (ls == NULL)
        return (NULL);
    ls->head = NULL;
    ls->len = 0;
    return (ls);
}
