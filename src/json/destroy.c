/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** destroy
*/

#include "my/json.h"
#include "my/mem.h"

void json_destroy(json_t *json_object)
{
    if (json_object->type == JSON_STRING)
        my_free(json_object->u.str);
    my_free(json_object);
}