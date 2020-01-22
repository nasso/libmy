/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_insert
*/

#include "my.h"
#include "cstr.h"
#include "collections/list.h"
#include "collections/hash_map.h"
#include "collections/hash_map_priv.h"

static const double MAX_LOAD_FACTOR = 0.75;

static int find_elem_with_key(void *user_data, void *raw_element)
{
    const char *key = user_data;
    hash_map_bucket_element_t *elem = raw_element;

    return (my_cstrcmp(key, elem->pair.key));
}

static bool ensure_exists(list_t **bucket_ptr)
{
    if (*bucket_ptr)
        return (false);
    *bucket_ptr = list_new();
    return (*bucket_ptr == NULL);
}

static hash_map_bucket_element_t *get_element(hash_map_t *self, const char *key)
{
    u64_t hash = self->fn(key);
    list_t **bucket_ptr = self->buckets + (hash % self->bucket_count);
    hash_map_bucket_element_t *elem = NULL;

    if (ensure_exists(bucket_ptr))
        return (NULL);
    elem = list_find_with(*bucket_ptr, &find_elem_with_key, (void*) key);
    if (elem == NULL) {
        elem = hash_map__bucket_element_new(hash, key);
        if (elem == NULL || list_push_back(*bucket_ptr, elem)) {
            hash_map__bucket_element_destroy(elem);
            return (NULL);
        }
        self->size++;
    }
    return (elem);
}

hash_map_insert_result_t hash_map_insert(hash_map_t *self, const char *key,
    void *value)
{
    hash_map_bucket_element_t *elem = get_element(self, key);
    void *old_value = NULL;

    if (elem == NULL)
        return ((hash_map_insert_result_t) ERR(true));
    if (((double) self->size / (double) self->bucket_count) >= MAX_LOAD_FACTOR)
        if (hash_map__grow(self, (usize_t) (self->bucket_count * (4.0 / 3.0))))
            return ((hash_map_insert_result_t) ERR(true));
    old_value = elem->pair.value;
    elem->pair.value = value;
    return ((hash_map_insert_result_t) OK(old_value));
}
