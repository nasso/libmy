/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map__grow
*/

#include <stdbool.h>
#include <stddef.h>
#include "mem.h"
#include "math.h"
#include "collections/list.h"
#include "collections/hash_map.h"
#include "collections/hash_map_priv.h"

struct grow_op_data {
    list_t **buckets;
    usize_t bucket_count;
    bool err;
};

static int export_entry_callback(void *user_data, void *raw_element)
{
    struct grow_op_data *data = user_data;
    hash_map_bucket_element_t *element = raw_element;
    list_t **bucket = &data->buckets[element->hash % data->bucket_count];

    if (*bucket == NULL) {
        *bucket = list_from(1, element);
        if (*bucket == NULL) {
            data->err = true;
            return (1);
        }
    } else
        data->err = list_push_back(*bucket, element);
    return (data->err ? 1 : 0);
}

static bool export_entries(hash_map_t *self, struct grow_op_data *data)
{
    if (self->buckets == NULL)
        return (false);
    for (usize_t i = 0; !data->err && i < self->bucket_count; i++)
        list_for_each(self->buckets[i], &export_entry_callback, data);
    if (!data->err)
        return (false);
    for (usize_t i = 0; i < data->bucket_count; i++)
        if (data->buckets[i] != NULL)
            list_destroy(data->buckets[i]);
    my_memset(data->buckets, 0, sizeof(list_t*) * data->bucket_count);
    return (true);
}

bool hash_map__grow(hash_map_t *self, usize_t new_size)
{
    struct grow_op_data data = {
        .buckets = my_calloc(new_size, sizeof(list_t*)),
        .bucket_count = new_size,
    };

    if (data.buckets == NULL)
        return (true);
    export_entries(self, &data);
    if (data.err) {
        my_free(data.buckets);
        return (true);
    }
    my_free(self->buckets);
    self->bucket_count = new_size;
    self->buckets = data.buckets;
    return (false);
}
