/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_remove
*/

#include "my.h"
#include "cstr.h"
#include "collections/list.h"
#include "collections/hash_map.h"
#include "collections/hash_map_priv.h"

static int find_callback(void *user_data, void *raw_element)
{
    const char *key = user_data;
    hash_map_bucket_element_t *element = raw_element;

    return (my_cstrcmp(key, element->pair.key));
}

void *hash_map_remove(hash_map_t *self, const char *key)
{
    u64_t hash = self->fn(key);
    list_t *bucket = self->buckets[hash % self->bucket_count];
    hash_map_bucket_element_t *elem = NULL;

    if (bucket == NULL)
        return (NULL);
    elem = list_remove_element(bucket, (void*) key, &find_callback);
    if (elem != NULL && bucket->len == self->biggest_size - 1)
        hash_map__refresh_stats(self);
    return (elem ? elem->pair.value : NULL);
}
