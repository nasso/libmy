/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** bool
*/

#include "my/json.h"
#include "my/cstr.h"
#include "my/my.h"

json_t *json_parse_null(const char *json_str, int *i)
{
    (void)json_str;
    (*i) += 4;
    return (json_create_null());
}