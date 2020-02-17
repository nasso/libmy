/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** object
*/

#include "my/json.h"
#include "my/mem.h"

json_t *json_create_object(void)
{
    json_t json_object = {JSON_OBJECT};
    json_t *json_mem = my_malloc(sizeof(json_t));

    if (!json_mem)
        return (NULL);
    json_object.u.obj_map = hash_map_new();
    return (my_memcpy(json_mem, &json_object, sizeof(json_t)));
}