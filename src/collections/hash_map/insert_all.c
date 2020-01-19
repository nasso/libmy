/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_insert_all_* functions
*/

#include <stdarg.h>
#include "collections/hash_map.h"

void hash_map_insert_all(hash_map_t *self, usize_t count, ...)
{
    va_list ap;

    va_start(ap, count);
    hash_map_insert_all_var(self, count, ap);
    va_end(ap);
}

void hash_map_insert_all_var(hash_map_t *self, usize_t count, va_list ap)
{
    const char *key = NULL;
    void *data = NULL;

    for (usize_t i = 0; i < count; i++) {
        key = va_arg(ap, const char*);
        data = va_arg(ap, void*);
        hash_map_insert(self, key, data);
    }
}
