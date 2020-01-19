/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Hash map data structure implementation
*/

#ifndef LIBMY_COLLECTIONS_HASH_MAP_H
#define LIBMY_COLLECTIONS_HASH_MAP_H

#include <stdarg.h>
#include <stdbool.h>
#include "collections/list.h"
#include "types.h"

typedef struct {
    const char *key;
    void *data;
} hash_map_pair_t;

typedef bool (hash_map_for_each_fn_t)(void *user_data, hash_map_pair_t *pair);
typedef u64_t (hash_map_hasher_fn_t)(const char*);

typedef struct {
    hash_map_hasher_fn_t *const fn;
    const usize_t bucked_count;
    list_t *buckets[];
} hash_map_t;

hash_map_t *hash_map_new(void);
hash_map_t *hash_map_from(usize_t, ...);
hash_map_t *hash_map_from_var(usize_t, va_list);
hash_map_t *hash_map_from_arr(usize_t, hash_map_pair_t*);
void hash_map_destroy(hash_map_t*);
void hash_map_destroy_with(hash_map_t*, hash_map_for_each_fn_t*, void*);
void hash_map_for_each(hash_map_t*, hash_map_for_each_fn_t*, void*);
void hash_map_clear(hash_map_t*, hash_map_for_each_fn_t*, void*);
void *hash_map_get(hash_map_t*, const char*);
void *hash_map_remove(hash_map_t*, const char*);
void *hash_map_insert(hash_map_t*, const char*, void*);

#endif /* LIBMY_COLLECTIONS_HASH_MAP_H */
