/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_clone
*/

#include "my/my.h"
#include "my/collections/hash_map.h"

struct clone_data {
    hash_map_t *map;
    void *(*clone)(void*);
    void (*destroy)(void*);
};

static int clone_pair_callback(void *user_data, hash_map_pair_t *pair)
{
    struct clone_data *data = user_data;
    void *value = data->clone ? data->clone(pair->value) : pair->value;

    return (!hash_map_insert(data->map, pair->key, value).is_ok);
}

static int destroy_pair_callback(void *user_data, hash_map_pair_t *pair)
{
    struct clone_data *data = user_data;

    if (data->destroy)
        data->destroy(pair->value);
    return (0);
}

hash_map_t *hash_map_clone_with(const hash_map_t *other, void *(*clone)(void*),
    void (*destroy)(void*))
{
    struct clone_data data = {
        .map = hash_map_with_hasher(other->fn),
        .clone = clone,
        .destroy = destroy,
    };

    if (data.map == NULL)
        return (NULL);
    if (hash_map_for_each((hash_map_t*) other, &clone_pair_callback, &data)) {
        hash_map_destroy_with(data.map, &destroy_pair_callback, &data);
        return (NULL);
    }
    return (data.map);
}

hash_map_t *hash_map_clone(const hash_map_t *other)
{
    return (hash_map_clone_with(other, NULL, NULL));
}
