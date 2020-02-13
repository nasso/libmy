/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** bool
*/

#include "my/json.h"
#include "my/mem.h"

json_t *json_create_bool(bool b)
{
    json_t json_object = {JSON_BOOL, {NULL}};
    json_t *json_mem = my_malloc(sizeof(json_t));

    if (!json_mem)
        return (NULL);
    json_object.u.bval = b;
    return (my_memcpy(json_mem, &json_object, sizeof(json_t)));
}