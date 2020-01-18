/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Returns the number of characters found in the string passed as parameter.
*/

#include <stddef.h>
#include "cstr.h"

size_t my_cstrlen(const char *str)
{
    size_t len = 0;

    while (str[len] != '\0')
        len++;
    return (len);
}
