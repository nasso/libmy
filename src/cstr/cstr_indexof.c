/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** cstr_indexof
*/

#include "my/my.h"

opt_i32_t my_cstr_indexof(const char *str, char c)
{
    for (i32_t i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return ((opt_i32_t)SOME(i));
    return ((opt_i32_t)NONE);
}