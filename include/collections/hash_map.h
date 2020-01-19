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
#include "my.h"
#include "collections/list.h"

typedef struct {
    const char *key;
    void *data;
} hash_map_pair_t;

typedef bool (hash_map_for_each_fn_t)(void *user_data, hash_map_pair_t *pair);
typedef u64_t (hash_map_hasher_fn_t)(const char*);
typedef list_t hash_map_bucket_t;

typedef struct {
    hash_map_hasher_fn_t *const fn;
    usize_t biggest_size;
    usize_t used_buckets;
    usize_t bucket_count;
    hash_map_bucket_t **buckets;
} hash_map_t;

hash_map_t *hash_map_new(void);
hash_map_t *hash_map_with_hasher(hash_map_hasher_fn_t*);
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
void hash_map_insert_all(hash_map_t*, usize_t, ...);
void hash_map_insert_all_var(hash_map_t*, usize_t, va_list);
bool hash_map_merge(hash_map_t*, const hash_map_t*);

#endif /* LIBMY_COLLECTIONS_HASH_MAP_H */
