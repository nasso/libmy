/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** number
*/

#include "my/json.h"
#include "my/mem.h"

json_t *json_create_number(f64_t num)
{
    json_t json_object = {JSON_NUMBER};
    json_t *json_mem = my_malloc(sizeof(json_t));

    if (!json_mem)
        return (NULL);
    json_object.u.nb = num;
    return (my_memcpy(json_mem, &json_object, sizeof(json_t)));
}