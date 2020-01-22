/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_clear
*/

#include <stddef.h>
#include "mem.h"
#include "collections/hash_map.h"
#include "collections/list.h"

static int destroy_entry_callback(void *user_data, void *raw_element)
{
    hash_map_bucket_element_t *element = raw_element;

    (void)(user_data);
    my_free((void*) element->pair.key);
    return (0);
}

void hash_map_clear(hash_map_t *self)
{
    for (usize_t i = 0; i < self->bucket_count; i++)
        if (self->buckets[i]) {
            list_destroy_with(self->buckets[i], &destroy_entry_callback, NULL);
            self->buckets[i] = NULL;
        }
    self->used_buckets = 0;
    self->biggest_size = 0;
}
