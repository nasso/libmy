/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map__refresh_stats
*/

#include "types.h"
#include "math.h"
#include "collections/list.h"
#include "collections/hash_map.h"
#include "collections/hash_map_priv.h"

void hash_map__refresh_stats(hash_map_t *self)
{
    list_t *bucket = NULL;

    self->biggest_size = 0;
    self->used_buckets = 0;
    for (usize_t i = 0; i < self->bucket_count; i++) {
        bucket = self->buckets[i];
        if (bucket == NULL)
            continue;
        self->biggest_size = my_max_usize_t(self->biggest_size, bucket->len);
        self->used_buckets++;
    }
}
