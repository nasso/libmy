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
    my_free(json_object);
}