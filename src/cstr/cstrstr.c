/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Implementation of strstr.
*/

#include <stddef.h>
#include "cstr.h"

char *my_cstrstr(char *str, const char *to_find)
{
    size_t len = 0;

    while (to_find[len] != '\0')
        len++;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (!my_cstrncmp(&str[i], to_find, len))
            return (&str[i]);
    return (0);
}
