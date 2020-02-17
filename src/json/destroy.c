/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** destroy
*/

#include "my/json.h"
#include "my/mem.h"

int subobject_destroy(void *user_data, hash_map_pair_t *subobj)
{
    (void)user_data;
    json_destroy((json_t*)subobj->value);
    return (0);
}

void json_destroy(json_t *json_object)
{
    switch (json_object->type) {
        case JSON_STRING:
            my_free(json_object->u.str);
            break;
        case JSON_ARRAY:
            for (i32_t i = 0; i < (i32_t)json_object->u.array.len; i++)
                json_destroy(json_object->u.array.data[i]);
            break;
        case JSON_OBJECT:
            hash_map_for_each(json_object->u.obj_map, &subobject_destroy, NULL);
            break;
        default:
            break;
    }
    my_free(json_object);
}