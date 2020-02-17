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
typedef RESULT(json_t*, bool) json_parse_result_t;

extern const char *json_identifiers;
extern const char *json_separators;

struct json_element {
    const enum {
        JSON_OBJECT,
        JSON_ARRAY,
        JSON_STRING,
        JSON_NUMBER,
        JSON_BOOL,
        JSON_NULL,
    } type;
    union {
        hash_map_t *obj_map;
        struct {
            usize_t len;
            json_t **data;
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

char *json_clean(const char *input_str);

void json_destroy(json_t*);

json_t *json_object_get(json_t*, const char*);
int json_object_set(json_t*, const char*, const json_t*);

json_t *json_idx(json_t*, usize_t);
usize_t json_len(json_t*);

json_t *json_parse_entity(const char*, int*);
json_t *json_parse_array(const char*, int*);
json_t *json_parse_string(const char*, int*);
json_t *json_parse_number(const char*, int*);
json_t *json_parse_object(const char*, int*);
json_t *json_parse_bool(const char*, int*);
json_t *json_parse_null(const char*, int*);

#endif /* LIBMY_JSON_H */
