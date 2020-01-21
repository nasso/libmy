/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map constructors
*/

#include "collections/hash_map.h"
#include "hash.h"
#include "mem.h"

hash_map_t *hash_map_new(void)
{
    return (hash_map_with_hasher(&my_djb2_cstr));
}

hash_map_t *hash_map_with_hasher(hash_map_hasher_fn_t *fn)
{
    hash_map_t init = {.fn = fn, .bucket_count = 32};
    hash_map_t *self = my_malloc(sizeof(hash_map_t));

    if (self == NULL)
        return (NULL);
    my_memcpy(self, &init, sizeof(hash_map_t));
    self->buckets = my_calloc(self->bucket_count, sizeof(list_t*));
    if (self->buckets == NULL) {
        my_free(self);
        return (NULL);
    }
    return (self);
}
