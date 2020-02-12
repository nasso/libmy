/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** JSON parser
*/

#ifndef LIBMY_JSON_H
#define LIBMY_JSON_H

#include "my/my.h"
#include "my/collections/hash_map.h"

typedef struct json_element json_t;

struct json_element {
    const enum {
        JSON_OBJECT,
        JSON_ARRAY,
        JSON_STRING,
        JSON_NUMBER,
        JSON_BOOL,
        JSON_NULL,
    } type;
    const union {
        hash_map_t *obj_map;
        struct {
            usize_t len;
            json_t *data;
        } array;
        char *str;
        f64_t nb;
        bool bval;
    } u;
};

json_t *json_create_object(void);
json_t *json_create_array(void);
json_t *json_create_string(const char*);
json_t *json_create_number(f64_t);
json_t *json_create_bool(bool);
json_t *json_create_null(void);

void json_destroy(json_t*);

json_t *json_get(json_t*, const char*);
json_t *json_set(json_t*, const char*);
json_t *json_idx(json_t*, usize_t);
usize_t json_len(json_t*);

#endif /* LIBMY_JSON_H */
