/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** bool
*/

#include "my/json.h"
#include "my/cstr.h"
#include "my/my.h"

json_t *json_parse_bool(const char *json_str, int *i)
{
    if (my_cstrncmp(json_str + (*i), "false", 5) == 0) {
        (*i) += 5;
        return (json_create_bool(false));
    } else if (my_cstrncmp(json_str + (*i), "true", 4) == 0) {
        (*i) += 4;
        return (json_create_bool(true));
    }
    return (NULL);
}
