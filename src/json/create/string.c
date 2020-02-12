/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** string
*/

#include "my/json.h"
#include "my/mem.h"
#include "my/cstr.h"

json_t *json_create_string(const char *str)
{
    json_t json_object = {JSON_STRING};
    json_t *json_mem = my_malloc(sizeof(json_t));

    if (!json_mem)
        return (NULL);
    json_object.u.str = my_cstrdup(str);
    return (my_memcpy(json_mem, &json_object, sizeof(json_t)));
}