/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** private hash_map functions
*/

#ifndef LIBMY_COLLECTIONS_HASH_MAP_PRIV_H
#define LIBMY_COLLECTIONS_HASH_MAP_PRIV_H

#include <stdbool.h>
#include "collections/hash_map.h"

bool hash_map__grow(hash_map_t*, usize_t);
bool hash_map__insert_entry(hash_map_t*, const hash_map_bucket_element_t*);

#endif /* LIBMY_COLLECTIONS_HASH_MAP_PRIV_H */
