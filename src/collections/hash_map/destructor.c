/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map destructors
*/

#include <stddef.h>
#include "my.h"
#include "collections/list.h"
#include "collections/hash_map.h"

static int free_pair_callback(void *user_data, void *raw_pair)
{
    hash_map_pair_t *pair = raw_pair;

    (void)(user_data);
    if (pair == NULL)
        return (0);
    my_free((void*) pair->key);
    my_free(pair);
    return (0);
}

static void destroy_bucket(hash_map_bucket_t *bucket)
{
    if (bucket == NULL)
        return;
    list_destroy_with(bucket, &free_pair_callback, NULL);
}

void hash_map_destroy(hash_map_t *self)
{
    if (self == NULL)
        return;
    if (self->buckets) {
        for (usize_t i = 0; i < self->bucket_count; i++)
            destroy_bucket(self->buckets[i]);
        my_free(self->buckets);
    }
    my_free(self);
}

void hash_map_destroy_with(hash_map_t *self, hash_map_for_each_fn_t *fn,
    void *user_data)
{
    if (fn != NULL)
        hash_map_for_each(self, fn, user_data);
    hash_map_destroy(self);
}
