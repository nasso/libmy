/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** object
*/

#include "my/my.h"
#include "my/json.h"

int json_object_set(json_t *obj, const char *name, const json_t *insert_obj)
{
    if (!obj || !obj->u.obj_map || obj->type != JSON_OBJECT)
        return (1);
    hash_map_insert(obj->u.obj_map, name, (void*)insert_obj);
    return (0);
}

json_t *json_object_get(json_t *obj, const char *name)
{
    if (!obj || !obj->u.obj_map || obj->type != JSON_OBJECT)
        return (NULL);
    return (hash_map_get(obj->u.obj_map, name));
}