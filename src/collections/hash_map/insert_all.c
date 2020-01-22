/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_insert_all_* functions
*/

#include <stdbool.h>
#include <stdarg.h>
#include "collections/hash_map.h"

bool hash_map_insert_all(hash_map_t *self, usize_t count, ...)
{
    bool err = false;
    va_list ap;

    va_start(ap, count);
    err = hash_map_insert_all_var(self, count, ap);
    va_end(ap);
    return (err);
}

bool hash_map_insert_all_var(hash_map_t *self, usize_t count, va_list ap)
{
    const char *key = NULL;
    bool err = false;
    void *data = NULL;

    for (usize_t i = 0; !err && i < count; i++) {
        key = va_arg(ap, const char*);
        data = va_arg(ap, void*);
        err |= !hash_map_insert(self, key, data).is_ok;
    }
    return (err);
}
