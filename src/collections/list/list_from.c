/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include <stdarg.h>
#include "collections/list.h"

list_t *list_from_arr(size_t count, void **data)
{
    list_t *ls = list_new();
    int err = 0;

    if (ls == NULL)
        return (NULL);
    while (!err && count--)
        err = list_push_back(ls, *(data++));
    if (err)
        list_destroy(ls);
    return (err ? NULL : ls);
}

list_t *list_from_var(size_t count, va_list ap)
{
    list_t *ls = list_new();
    int err = 0;

    if (ls == NULL)
        return (NULL);
    while (!err && count--)
        err = list_push_back(ls, va_arg(ap, void*));
    if (err)
        list_destroy(ls);
    return (err ? NULL : ls);
}

list_t *list_from(size_t count, ...)
{
    list_t *ls = NULL;
    va_list ap;

    va_start(ap, count);
    ls = list_from_var(count, ap);
    va_end(ap);
    return (ls);
}
