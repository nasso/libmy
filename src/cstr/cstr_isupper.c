/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Returns true if the given string contains only uppercase letters.
*/

#include <stddef.h>
#include <stdbool.h>
#include "cstr.h"

bool my_cstr_isupper(const char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return (false);
    return (true);
}
