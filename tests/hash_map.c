/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map tests
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "my/my.h"
#include "my/cstr.h"
#include "my/collections/hash_map.h"
#include "my/collections/list.h"

static int put_in_list(void *user_data, hash_map_pair_t *pair)
{
    list_t *ls = user_data;

    list_push_back(ls, pair);
    return (0);
}

static int pair_cmp(void *a, void *b)
{
    hash_map_pair_t *pa = a;
    hash_map_pair_t *pb = b;

    return (!my_cstrcmp(pa->key, pb->key) && !my_cstrcmp(pa->value, pb->value));
}

static char *randstr(usize_t n)
{
    char *str = my_calloc(sizeof(char), n + 1);

    for (usize_t i = 0; i < n; i++)
        str[i] = 'a' + (rand() % 26);
    str[n] = '\0';
    return (str);
}

Test(hash_map, new)
{
    hash_map_t *map = hash_map_new();

    cr_assert_not_null(map);
}

Test(hash_map, destroy)
{
    hash_map_t *map = hash_map_new();

    hash_map_destroy(map);
}

Test(hash_map, insert)
{
    hash_map_t *map = hash_map_new();
    hash_map_insert_result_t result = hash_map_insert(map, "foo", "bar");

    cr_assert(result.is_ok);
    cr_assert_null(result.u.ok);
    hash_map_destroy(map);
}

Test(hash_map, insert_exists_already)
{
    hash_map_t *map = hash_map_new();
    hash_map_insert_result_t result;

    hash_map_insert(map, "foo", "bar");
    result = hash_map_insert(map, "foo", "not bar");
    cr_assert(result.is_ok);
    cr_assert_str_eq(result.u.ok, "bar");
    hash_map_destroy(map);
}

Test(hash_map, get)
{
    hash_map_t *map = hash_map_new();

    hash_map_insert(map, "foo", "bar");
    cr_assert_str_eq(hash_map_get(map, "foo"), "bar");
    cr_assert_null(hash_map_get(map, "bar"));
    hash_map_destroy(map);
}

Test(hash_map, insert_all)
{
    hash_map_t *map = hash_map_new();

    hash_map_insert_all(map, 2, "foo", "bar", "bar", "foo");
    cr_assert_str_eq(hash_map_get(map, "foo"), "bar");
    cr_assert_str_eq(hash_map_get(map, "bar"), "foo");
    hash_map_destroy(map);
}

Test(hash_map, from)
{
    hash_map_t *map = hash_map_from(2, "foo", "bar", "bar", "foo");

    cr_assert_str_eq(hash_map_get(map, "foo"), "bar");
    cr_assert_str_eq(hash_map_get(map, "bar"), "foo");
    hash_map_destroy(map);
}

Test(hash_map, insert_all_arr)
{
    hash_map_t *map = hash_map_new();
    hash_map_pair_t pairs[2] = {
        {"foo", "bar"},
        {"bar", "foo"},
    };

    hash_map_insert_all_arr(map, 2, pairs);
    cr_assert_str_eq(hash_map_get(map, "foo"), "bar");
    cr_assert_str_eq(hash_map_get(map, "bar"), "foo");
    hash_map_destroy(map);
}

Test(hash_map, from_arr)
{
    hash_map_pair_t pairs[2] = {
        {"foo", "bar"},
        {"bar", "foo"},
    };
    hash_map_t *map = hash_map_from_arr(2, pairs);

    cr_assert_str_eq(hash_map_get(map, "foo"), "bar");
    cr_assert_str_eq(hash_map_get(map, "bar"), "foo");
    hash_map_destroy(map);
}

Test(hash_map, remove)
{
    hash_map_t *map = hash_map_from(2, "foo", "bar", "bar", "foo");

    cr_assert_str_eq(hash_map_remove(map, "foo"), "bar");
    cr_assert_null(hash_map_get(map, "foo"));
    cr_assert_str_eq(hash_map_get(map, "bar"), "foo");
    hash_map_destroy(map);
}

Test(hash_map, clear)
{
    hash_map_t *map = hash_map_from(2, "foo", "bar", "bar", "foo");

    hash_map_clear(map);
    cr_assert_null(hash_map_get(map, "foo"));
    cr_assert_null(hash_map_get(map, "bar"));
    hash_map_destroy(map);
}

Test(hash_map, for_each)
{
    list_t *ls = list_new();
    hash_map_t *map = hash_map_from(2, "foo", "bar", "bar", "foo");
    hash_map_pair_t pairs[2] = {
        {"foo", "bar"},
        {"bar", "foo"},
    };

    hash_map_for_each(map, &put_in_list, ls);
    cr_assert_eq(ls->len, 2);
    cr_assert_not_null(list_find_with(ls, &pair_cmp, &pairs[0]));
    cr_assert_not_null(list_find_with(ls, &pair_cmp, &pairs[1]));
    hash_map_destroy(map);
}

Test(hash_map, clear_with)
{
    list_t *ls = list_new();
    hash_map_t *map = hash_map_from(2, "foo", "bar", "bar", "foo");
    hash_map_pair_t pairs[2] = {
        {"foo", "bar"},
        {"bar", "foo"},
    };

    hash_map_clear_with(map, &put_in_list, ls);
    cr_assert_null(hash_map_get(map, "foo"));
    cr_assert_null(hash_map_get(map, "bar"));
    cr_assert_eq(ls->len, 2);
    cr_assert_not_null(list_find_with(ls, &pair_cmp, &pairs[0]));
    cr_assert_not_null(list_find_with(ls, &pair_cmp, &pairs[1]));
    hash_map_destroy(map);
}

Test(hash_map, destroy_with)
{
    list_t *ls = list_new();
    hash_map_t *map = hash_map_from(2, "foo", "bar", "bar", "foo");
    hash_map_pair_t pairs[2] = {
        {"foo", "bar"},
        {"bar", "foo"},
    };

    hash_map_destroy_with(map, &put_in_list, ls);
    cr_assert_eq(ls->len, 2);
    cr_assert_not_null(list_find_with(ls, &pair_cmp, &pairs[0]));
    cr_assert_not_null(list_find_with(ls, &pair_cmp, &pairs[1]));
}

Test(hash_map, lots_of_values)
{
    char *keys[10000] = {NULL};
    u8_t values[10000] = {0};
    hash_map_t *map = hash_map_new();

    for (usize_t i = 0; i < 10000; i++) {
        keys[i] = randstr(64);
        values[i] = i;
        hash_map_insert(map, keys[i], &values[i]);
    }
    cr_assert_leq((double) map->size / (double) map->bucket_count, 1.0);
    for (usize_t i = 0; i < 10000; i++)
        cr_assert_eq(hash_map_get(map, keys[i]), &values[i]);
    for (usize_t i = 0; i < 10000; i++)
        my_free(keys[i]);
    hash_map_destroy(map);
}

Test(hash_map, clone)
{
    hash_map_t *map = hash_map_from(2, "foo", "bar", "bar", "foo");
    hash_map_t *clone = hash_map_clone(map);

    cr_assert_str_eq(hash_map_get(clone, "foo"), "bar");
    cr_assert_str_eq(hash_map_get(clone, "bar"), "foo");
    hash_map_destroy(map);
}

Test(hash_map, clone_with)
{
    hash_map_t *map = hash_map_from(2, "foo", "bar", "bar", "foo");
    hash_map_t *clone = hash_map_clone_with(map, (void *(*)(void*)) &my_cstrdup,
        &my_free);

    cr_assert_str_eq(hash_map_get(clone, "foo"), "bar");
    cr_assert_str_eq(hash_map_get(clone, "bar"), "foo");
    hash_map_destroy(map);
}
